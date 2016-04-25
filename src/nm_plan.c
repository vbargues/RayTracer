/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:34:26 by vbargues          #+#    #+#             */
/*   Updated: 2016/02/12 10:34:28 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include "libft.h"
#include <math.h>

static t_point	normalize(t_point vec)
{
	float	norme;

	norme = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	vec.x /= norme;
	vec.y /= norme;
	vec.z /= norme;
	return (vec);
}

t_color			texture_plan(t_obj object, t_point inter)
{
	float	x;
	float	y;
	int		colo;
	t_point	rot;
	t_plan	*tmp;

	normal = normal_sphere(*(t_sphere *)(obj.obj), inter, ray);
	if (!object.texture)
		return (object.color);
	tmp = ((t_plan *)object.obj);
	rot = vec_dir(new_point(0, 0, 0), new_point(tmp->a, tmp->b, tmp->c));
	x = rot.x + rot.y + rot.z;
	inter = rot_point(new_point(inter.x - rot.x * (tmp->d / (tmp->a + tmp->b +
		tmp->c)), inter.y - rot.y * (tmp->d / (tmp->a + tmp->b + tmp->c)),
	inter.z - rot.z * (tmp->d / (tmp->a + tmp->b + tmp->c))),
	get_rot_mat(M_PI / 2 * rot.z / x, 0, -M_PI / 2 * rot.x / x));
	colo = 0;
	x = (inter.x - floor(inter.x / 30) * 30) / 30 * object.texture->width;
	y = (10 - (inter.z - floor(inter.z / 10) * 10))
		/ 10 * object.texture->height;
	ft_memcpy(&colo, object.texture->data + ((int)x * (object.texture->bpp /
		8)) + ((int)y * object.texture->sl), 3);
	return (normalize(new_point((def.red * 2 - 255) / 255 + normal.x,
		-(def.green * 2 - 255) / 255 + normal.y, (def.blue * 2 - 255)
		/ 255 + normal.z)));
}
