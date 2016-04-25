/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:47:55 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:00 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include "libft/includes/libft.h"
#include <math.h>

static float	ft_delta(t_cone cone, t_vector *ray, float *r2)
{
	float		a;
	float		b;
	float		c;
	float		tan2;
	float		delta;

	ray->origin = rot_point(new_point(ray->origin.x - cone.center.x,
		ray->origin.y - cone.center.y, ray->origin.z - cone.center.z),
		cone.rot.negm16);
	ray->dir = rot_point(ray->dir, cone.rot.negm16);
	tan2 = pow(tan(cone.angle), 2);
	a = (pow(ray->dir.x, 2) + pow(ray->dir.z, 2)) - tan2 * pow(ray->dir.y, 2);
	b = (2 * (ray->origin.x * ray->dir.x + ray->origin.z * ray->dir.z)
			- 2 * tan2 * ray->origin.y * ray->dir.y);
	c = (pow(ray->origin.x, 2) + pow(ray->origin.z, 2))
		- tan2 * pow(ray->origin.y, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta <= 0)
		return (-1);
	*r2 = (-b - sqrt(delta)) / (2 * a);
	return ((-b + sqrt(delta)) / (2 * a));
}

static	float	test_top(t_cone cone, t_vector ray)
{
	float	dist;
	t_point	inter;

	if (ray.dir.y == 0)
		return (-1);
	dist = (-cone.top - ray.origin.y) / ray.dir.y;
	inter = new_point(ray.origin.x + ray.dir.x * dist, -cone.top,
					ray.origin.z + ray.dir.z * dist);
	if (pow(inter.x, 2) + pow(inter.z, 2) < pow(inter.y, 2)
			* pow(tan(cone.angle), 2))
		return (dist);
	return (-1);
}

static	float	test_bot(t_cone cone, t_vector ray)
{
	float	dist;
	t_point	inter;

	if (ray.dir.y == 0)
		return (-1);
	dist = (cone.bot - ray.origin.y) / ray.dir.y;
	inter = new_point(ray.origin.x + ray.dir.x * dist, cone.bot,
					ray.origin.z + ray.dir.z * dist);
	if (pow(inter.x, 2) + pow(inter.z, 2) < pow(inter.y, 2)
			* pow(tan(cone.angle), 2))
		return (dist);
	return (-1);
}

static	float	alanorme(t_cone cone, t_vector ray, double *dist)
{
	float		tmp;
	int			retval;

	retval = 0;
	tmp = test_top(cone, ray);
	if (tmp > 0.1 && ((double)tmp < *dist || *dist == -1.0))
	{
		*dist = (double)tmp;
		retval = 1;
	}
	tmp = test_bot(cone, ray);
	if (tmp > 0.1 && ((double)tmp < *dist || *dist == -1.0))
	{
		*dist = (double)tmp;
		retval = 1;
	}
	return (retval);
}

int				cone_inter(t_cone cone, t_vector ray, double *dist)
{
	float		r1;
	float		r2;
	float		tmp;
	int			retval;

	retval = 0;
	r1 = ft_delta(cone, &ray, &r2);
	tmp = r1;
	tmp = ray.origin.y + ray.dir.y * r1;
	if (tmp < cone.bot && tmp > -cone.top)
		if (r1 > 0.1 && ((double)r1 < *dist || *dist == -1.0))
		{
			ft_putstr_fd("", -1);
			*dist = (double)r1;
			retval = 1;
		}
	tmp = ray.origin.y + ray.dir.y * r2;
	if (tmp < cone.bot && tmp > -cone.top)
		if (r2 > 0.1 && ((double)r2 < *dist || *dist == -1.0))
		{
			*dist = (double)r2;
			retval = 1;
		}
	retval += alanorme(cone, ray, dist);
	return (retval);
}
