/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:53:44 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 15:54:29 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include <string.h>
#include "libft/includes/libft.h"

static t_color	calc_color(t_color color, t_color obj_color,
							t_light light, double scalar)
{
	return (new_color(color.red + obj_color.red * scalar *
					light.color.red / 255 * light.intensity,
					color.blue + obj_color.blue * scalar *
					light.color.blue / 255 * light.intensity,
					color.green + obj_color.green * scalar *
					light.color.green / 255 * light.intensity));
}

static int		norm_is_shit(t_scene scene, t_light light,
								t_point inter, double norm)
{
	t_obj		obj;
	double		dist;

	dist = -1;
	if (find_closest_inter(scene.lst_obj, &obj, &dist,
		new_vector(light.body.center,
		vec_dir(light.body.center, inter))) && fabs(dist - norm) < 1)
		return (1);
	return (0);
}

static t_color	get_spec(t_scene scene, t_light light,
						t_point light_inter, t_obj object)
{
	t_point		r;
	float		dot;
	float		reflet;

	reflet = 2.0f * scene.scal;
	r = new_point(light_inter.x - reflet * scene.normal.x, light_inter.y -
		reflet * scene.normal.y, light_inter.z - reflet * scene.normal.z);
	dot = scalar_prod(scene.ray, r);
	if (dot < 0.0f)
	{
		reflet = powf(dot, 20) * object.spec * light.intensity;
		scene.color = new_color(scene.color.red + reflet * light.color.red,
			scene.color.blue + reflet * light.color.blue,
			scene.color.green + reflet * light.color.green);
	}
	return (scene.color);
}

t_color			get_ambiant_light(t_scene scene, t_vector ray,
									t_obj object, t_point inter)
{
	t_llst		*tmp;
	t_point		light_inter;
	double		norm;

	tmp = scene.lst_light;
	scene.color = new_color(0, 0, 0);
	while (tmp)
	{
		light_inter = new_point(inter.x - tmp->light->body.center.x, inter.y -
			tmp->light->body.center.y, inter.z - tmp->light->body.center.z);
		norm = sqrt(pow(light_inter.x, 2) + pow(light_inter.y, 2) +
				pow(light_inter.z, 2));
		scene.normal = object.normal(object, inter, ray);
		light_inter = new_point((double)light_inter.x / norm,
						light_inter.y / norm, light_inter.z / norm);
		scene.scal = scalar_prod(light_inter, scene.normal);
		scene.ray = ray.dir;
		if (norm_is_shit(scene, *(tmp->light), inter, norm) &&
				scene.scal >= 0.000000000000000000001)
			scene.color = calc_color(get_spec(scene, *(tmp->light),
			light_inter, object), object.texturing(object, inter, ray),
			*(tmp->light), scene.scal);
		tmp = tmp->next;
	}
	return (scene.color);
}
