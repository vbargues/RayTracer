/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_para.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:31:16 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:31:17 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static t_point	normal_para(t_para para, t_point inter, t_vector ray)
{
	(void)ray;
	inter = rot_point(new_point(inter.x - para.center.x, inter.y -
								para.center.y, inter.z - para.center.z),
								para.rot.negm16);
	if (inter.y <= 0)
	{
		return (rot_point(vec_dir(new_point(2 * inter.x / pow(para.a, 2), -1,
			2 * inter.z / pow(para.b, 2)), new_point(0, 0, 0)), para.rot.m16));
	}
	return (rot_point(vec_dir(new_point(2 * inter.x / pow(para.a, 2), 1,
		2 * inter.z / pow(para.b, 2)), new_point(0, 0, 0)), para.rot.m16));
}

t_point			call_normal_para(t_obj obj, t_point inter, t_vector ray)
{
	return (normal_para(*(t_para *)(obj.obj), inter, ray));
}
