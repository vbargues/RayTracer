/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:29:02 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:29:05 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include "libft/includes/libft.h"

t_color	texture_sphere(t_obj object, t_point normal, t_vector ray)
{
	float	phi;
	float	u;
	float	v;
	float	theta;
	int		colo;

	if ((colo = 0) || !object.texture)
		return (object.color);
	normal = normal_sphere(*(t_sphere *)(object.obj), normal, ray);
	phi = acos(-scalar_prod(new_point(0, -1, 0), normal));
	v = phi / M_PI;
	theta = acos(fmod(scalar_prod(normal, new_point(0, 0, -1)), 1) /
		sin(phi)) / (2 * M_PI);
	u = (scalar_prod(new_point(1, 0, 0), normal) > 0) ? theta : 1 - theta;
	if (scalar_prod(normal, new_point(0, 0, -1)) / sin(phi) < -1)
		u = 0.5;
	u = (int)ceil(u * object.texture->width * object.rep)
		% (int)object.texture->width;
	v = (int)ceil(v * object.texture->height * object.rep) %
		(int)object.texture->height;
	ft_memcpy(&colo, object.texture->data + ((int)u *
		(object.texture->bpp / 8)) + ((int)v * object.texture->sl), 3);
	return (color_int(colo));
}
