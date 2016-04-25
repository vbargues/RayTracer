/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:40:47 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/04 17:41:03 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include "libft/includes/libft.h"

t_point			normal_sphere(t_sphere sph, t_point inter, t_vector ray)
{
	(void)ray;
	return (vec_dir(inter, sph.center));
}

static t_point	normalize(t_point vec)
{
	float	norme;

	norme = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	vec.x /= norme;
	vec.y /= norme;
	vec.z /= norme;
	return (vec);
}

static t_color	norme(float u, float v, t_obj obj)
{
	int		x;
	int		y;
	int		colo;

	colo = 0;
	x = (int)ceil(u * obj.normal_map->width * obj.rep) %
	(int)obj.normal_map->width;
	y = (int)ceil(v * obj.normal_map->height * obj.rep) %
	(int)obj.normal_map->height;
	ft_memcpy(&colo, obj.normal_map->data + (x * (obj.normal_map->bpp / 8)) +
		(y * obj.normal_map->sl), 3);
	return (color_int(colo));
}

t_point			call_normal_sphere(t_obj obj, t_point inter, t_vector ray)
{
	t_point normal;
	t_point	norm_def;
	float	phi;
	float	theta;
	t_color	def;

	normal = normal_sphere(*(t_sphere *)(obj.obj), inter, ray);
	if (!obj.normal_map)
		return (normal);
	phi = acos(-scalar_prod(new_point(0, -1, 0), normal));
	theta = acos(fmod(scalar_prod(normal, new_point(0, 0, -1)), 1) /
		sin(phi)) / (2 * M_PI);
	if (scalar_prod(new_point(1, 0, 0), normal) > 0)
		;
	else
		theta = 1 - theta;
	if (scalar_prod(normal, new_point(0, 0, -1)) / sin(phi) < -1)
		theta = 0.5;
	def = norme(theta, (phi / M_PI), obj);
	norm_def = rot_point(new_point((def.red * 2 - 255) / 255,
	-(def.green * 2 - 255) / 255, (def.blue * 2 - 255) / 255),
	get_rot_mat(M_PI / 2 - phi, theta, 0));
	return (normalize(new_point(norm_def.x + normal.x, norm_def.y + normal.y,
								norm_def.z + normal.z)));
}
