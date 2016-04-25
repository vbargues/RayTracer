/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:33:18 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:33:20 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../rt.h"

static t_point	get_symetric(t_point a, t_vector normal)
{
	t_point	ret;
	float	k_mini;

	k_mini = (normal.dir.x * (a.x - normal.origin.x) + normal.dir.y * (a.y -
			normal.origin.y) + normal.dir.z * (a.z - normal.origin.z)) /
			(pow(normal.dir.x, 2) + pow(normal.dir.y, 2)
								+ pow(normal.dir.z, 2));
	ret = new_point(k_mini * normal.dir.x + normal.origin.x, k_mini *
			normal.dir.y + normal.origin.y, k_mini *
			normal.dir.z + normal.origin.z);
	ret = new_point(2 * ret.x - a.x, 2 * ret.y - a.y, 2 * ret.z - a.z);
	return (ret);
}

t_color			get_reflect(t_scene scene, t_vector ray, t_obj object,
						t_point inter)
{
	t_color		color;
	t_color		new_col;
	double		dist;

	color = new_color(0, 0, 0);
	scene.refl *= object.brightness;
	if (scene.depth-- == 0 || scene.refl < 0.01)
		return (color);
	dist = -1;
	ray.dir = vec_dir(inter, get_symetric(ray.origin,
						new_vector(inter, object.normal(object, inter, ray))));
	ray.origin = inter;
	if (find_closest_inter(scene.lst_obj, &object, &dist, ray) < 0)
		return (color);
	inter = new_point(ray.origin.x + dist * ray.dir.x, ray.origin.y +
		dist * ray.dir.y, ray.origin.z + dist * ray.dir.z);
	new_col = get_first_ray(scene, ray, object, inter);
	color = get_ambiant_light(scene, ray, object, inter);
	color = new_color(scene.refl * new_col.red + color.red, scene.refl *
		new_col.blue + color.blue, scene.refl * new_col.green + color.green);
	return (new_color(new_col.red + color.red, new_col.blue + color.blue,
						new_col.green + color.green));
}

t_color			get_first_ray(t_scene scene, t_vector ray, t_obj object,
							t_point inter)
{
	t_color		reflect;
	t_color		refract;

	if (scene.depth-- == 0 || scene.refl < 0.01)
		return (new_color(0, 0, 0));
	reflect = get_reflect(scene, ray, object, inter);
	refract = get_refract(scene, ray, object, inter);
	return (new_color(reflect.red + refract.red,
		reflect.blue + refract.blue, reflect.green + refract.green));
}
