/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:00 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:50:02 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include "libft/includes/libft.h"
#include <math.h>

static t_point	normalize(t_point vec)
{
	float		norme;

	norme = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	vec.x /= norme;
	vec.y /= norme;
	vec.z /= norme;
	return (vec);
}

static t_point	normal_plan(t_plan plan, t_point inter, t_vector ray)
{
	t_point		normal;

	normal = vec_dir(new_point(0, 0, 0),
			new_point(plan.a + cos(inter.x * plan.def.x) * plan.def.x,
						plan.b + cos(inter.y * plan.def.y) * plan.def.y,
						plan.c + cos(inter.z * plan.def.z) * plan.def.z));
	if (scalar_prod(ray.dir, normal) < 0)
		return (new_point(-normal.x, -normal.y, -normal.z));
	return (normal);
}

static float	nor_x(t_obj obj, t_point inter)
{
	float		x;

	x = inter.x - floor(inter.x / obj.text_x) * obj.text_x;
	x = x / obj.text_x * obj.normal_map->width;
	return (x);
}

static int		nor_y(t_obj obj, t_point inter)
{
	float		y;

	y = inter.z - floor(inter.z / obj.text_y) * obj.text_y;
	y = (obj.text_y - y) / obj.text_y * obj.normal_map->height;
	return (y);
}

t_point			call_normal_plan(t_obj obj, t_point inter, t_vector ray)
{
	int			colo;
	t_point		rot;
	float		calc;
	t_plan		*tmp;
	t_point		normal;

	normal = normal_plan(*(t_plan *)(obj.obj), inter, ray);
	if (!obj.normal_map)
		return (normal);
	tmp = ((t_plan *)obj.obj);
	rot = vec_dir(new_point(0, 0, 0), new_point(tmp->a, tmp->b, tmp->c));
	calc = rot.x + rot.y + rot.z;
	inter = rot_point(new_point(inter.x - rot.x * (tmp->d / (tmp->a + tmp->b +
		tmp->c)), inter.y - rot.y * (tmp->d / (tmp->a + tmp->b + tmp->c)),
		inter.z - rot.z * (tmp->d / (tmp->a + tmp->b + tmp->c))),
		get_rot_mat(M_PI / 2 * rot.z / calc, 0, -M_PI / 2 * rot.x / calc));
	colo = 0;
	ft_memcpy(&colo, obj.normal_map->data + ((int)nor_x(obj, inter)
		* (obj.normal_map->bpp / 8))
		+ ((int)nor_y(obj, inter) * obj.normal_map->sl), 3);
	return (normalize(new_point(((color_int(colo)).red * 2 - 255) / 255 +
		normal.x, -((color_int(colo)).green * 2 - 255) / 255 + normal.y,
		((color_int(colo)).blue * 2 - 255) / 255 + normal.z)));
}
