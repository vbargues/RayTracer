/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:49:50 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:49:52 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static t_point	normal_cylinder(t_cylinder cyl, t_point inter, t_vector ray)
{
	t_point		dir;
	float		k_mini;

	(void)ray;
	dir = vec_dir(cyl.top, cyl.center);
	if (scalar_prod(dir, vec_dir(cyl.top, inter)) < 0.001f && scalar_prod(dir,
						vec_dir(cyl.top, inter)) > -0.001f)
		return (dir);
	if (scalar_prod(dir, vec_dir(cyl.bot, inter)) < 0.001f && scalar_prod(dir,
						vec_dir(cyl.bot, inter)) > -0.001f)
		return (new_point(-dir.x, -dir.y, -dir.z));
	k_mini = (dir.x * (inter.x - cyl.center.x) + dir.y * (inter.y -
			cyl.center.y) + dir.z * (inter.z - cyl.center.z)) /
			(pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));
	return (vec_dir(inter, new_point(k_mini * dir.x + cyl.center.x, k_mini *
			dir.y + cyl.center.y, k_mini * dir.z + cyl.center.z)));
}

t_point			call_normal_cylinder(t_obj obj, t_point inter, t_vector ray)
{
	return (normal_cylinder(*(t_cylinder *)(obj.obj), inter, ray));
}
