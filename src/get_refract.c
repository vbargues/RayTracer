/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:34:15 by vbargues          #+#    #+#             */
/*   Updated: 2016/02/12 10:34:18 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../rt.h"

static t_point	get_refracted_ray(t_vector ray, t_point normal,
									float n1, float n2)
{
	float		costheta;
	t_point		vect;
	float		rap;
	float		useless_var;

	vect = new_point(-ray.dir.x, -ray.dir.y, -ray.dir.z);
	costheta = scalar_prod(vect, normal);
	rap = n1 / n2;
	useless_var = costheta + rap * scalar_prod(ray.dir, normal);
	normal = new_point(normal.x * useless_var, normal.y * useless_var,
		normal.z * useless_var);
	ray.dir = new_point(rap * ray.dir.x, rap * ray.dir.y, rap * ray.dir.z);
	return (new_point(ray.dir.x - normal.x, ray.dir.y - normal.y,
		ray.dir.z - normal.z));
}

static t_color	plouf(t_scene scene, t_vector ray, t_obj object,
				t_point inter)
{
	double		dist;
	t_point		normal;
	t_color		color;
	t_color		new_col;
	t_color		color2;

	dist = -1;
	normal = object.normal(object, inter, ray);
	normal = new_point(-normal.x, -normal.y, -normal.z);
	ray = new_vector(inter,
		get_refracted_ray(ray, normal, 2 - object.indice, 1));
	if (find_closest_inter(scene.lst_obj, &object, &dist, ray) < 0)
		return (scene.color);
	inter = new_point(ray.origin.x + dist * ray.dir.x, ray.origin.y +
	dist * ray.dir.y, ray.origin.z + dist * ray.dir.z);
	color2 = get_ambiant_light(scene, ray, object, inter);
	color = new_color(scene.refl * color2.red + scene.color.red,
		scene.refl * color2.blue + scene.color.blue,
		scene.refl * color2.green + scene.color.green);
	new_col = get_first_ray(scene, ray, object, inter);
	return (new_color(new_col.red + color.red, new_col.blue + color.blue,
				new_col.green + color.green));
}

t_color			get_refract(t_scene scene, t_vector ray, t_obj object,
				t_point inter)
{
	double		dist;
	t_point		normal;
	t_color		color;
	t_color		new_col;
	float		id;

	scene.refl *= object.transpa;
	if ((dist = -1) && (scene.depth-- == 0 || scene.refl < 0.01))
		return (new_color(0, 0, 0));
	id = object.id;
	normal = object.normal(object, inter, ray);
	ray = new_vector(inter, get_refracted_ray(ray, normal, 1, object.indice));
	if (find_closest_inter(scene.lst_obj, &object, &dist, ray) < 0)
		return (new_color(0, 0, 0));
	inter = new_point(ray.origin.x + dist * ray.dir.x, ray.origin.y +
		dist * ray.dir.y, ray.origin.z + dist * ray.dir.z);
	color = get_ambiant_light(scene, ray, object, inter);
	color = new_color(scene.refl * color.red,
		scene.refl * color.blue, scene.refl * color.green);
	scene.color = color;
	if (id == object.id)
		return (plouf(scene, ray, object, inter));
	new_col = get_first_ray(scene, ray, object, inter);
	return (new_color(new_col.red + color.red, new_col.blue + color.blue,
				new_col.green + color.green));
}
