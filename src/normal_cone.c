/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:49:41 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:49:43 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static t_point	normal_cone(t_cone cone, t_point inter, t_vector ray)
{
	float		norm;

	(void)ray;
	inter = rot_point(new_point(inter.x - cone.center.x, inter.y -
								cone.center.y, inter.z - cone.center.z),
								cone.rot.negm16);
	if (fabs(inter.y + cone.top) < 0.00001)
		return (cone.dir);
	if (fabs(inter.y - cone.bot) < 0.00001)
		return (new_point(-cone.dir.x, -cone.dir.y, -cone.dir.z));
	norm = sqrt(pow(inter.x, 2) + pow(inter.z, 2));
	if (inter.y <= 0)
	{
		return (rot_point(vec_dir(new_point(inter.x, norm * sin(cone.angle),
			inter.z), new_point(0, 0, 0)), cone.rot.m16));
	}
	return (rot_point(vec_dir(new_point(inter.x, -norm * sin(cone.angle),
		inter.z), new_point(0, 0, 0)), cone.rot.m16));
}

t_point			call_normal_cone(t_obj obj, t_point inter, t_vector ray)
{
	return (normal_cone(*(t_cone *)(obj.obj), inter, ray));
}
