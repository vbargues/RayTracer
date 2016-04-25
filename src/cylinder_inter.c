/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:48:37 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:39 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static float	ft_delta(t_cylinder cyl, t_vector *ray, float *r2)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	ray->origin = rot_point(new_point(ray->origin.x - cyl.center.x,
		ray->origin.y - cyl.center.y, ray->origin.z - cyl.center.z),
		cyl.rot.negm16);
	ray->dir = rot_point(ray->dir, cyl.rot.negm16);
	a = pow(ray->dir.x, 2) + pow(ray->dir.z, 2);
	b = 2 * ray->dir.x * ray->origin.x + 2 * ray->dir.z * ray->origin.z;
	c = pow(ray->origin.x, 2) + pow(ray->origin.z, 2) - pow(cyl.radius, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta <= 0)
		return (-1);
	*r2 = (-b - sqrt(delta)) / (2 * a);
	return ((-b + sqrt(delta)) / (2 * a));
}

static int		test_top(t_cylinder cyl, t_vector ray, double *dist, float y2)
{
	float	th;

	if (y2 < -cyl.height / 2)
		return (0);
	th = (-cyl.height / 2 - ray.origin.y) / ray.dir.y;
	if (th <= 0)
		return (0);
	if (th < *dist || *dist == -1)
	{
		*dist = th;
		return (1);
	}
	return (0);
}

static int		test_center(double *dist, float r1)
{
	if (r1 <= 0)
		return (0);
	if (r1 < *dist || *dist == -1)
	{
		*dist = r1;
		return (1);
	}
	return (0);
}

static int		test_bot(t_cylinder cyl, t_vector ray, double *dist, float y2)
{
	float	th;

	if (y2 > cyl.height / 2)
		return (0);
	th = (cyl.height / 2 - ray.origin.y) / ray.dir.y;
	if (th <= 0)
		return (0);
	if (th < *dist || *dist == -1)
	{
		*dist = th;
		return (1);
	}
	return (0);
}

int				cylinder_inter(t_cylinder cyl, t_vector ray, double *dist)
{
	float	r1;
	float	r2;
	float	tmp;
	float	y1;
	float	y2;

	r1 = ft_delta(cyl, &ray, &r2);
	if (r1 < 0 && r2 < 0)
		return (0);
	if ((r1 > r2 && r2 > 0.01) || (r1 < 0.01 && r2 < r1))
	{
		tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
	y1 = ray.origin.y + ray.dir.y * r1;
	y2 = ray.origin.y + ray.dir.y * r2;
	if (y1 < -cyl.height / 2)
		return (test_top(cyl, ray, dist, y2));
	else if (y1 >= -cyl.height / 2 && y1 <= cyl.height / 2)
		return (test_center(dist, r1));
	else if (y1 > cyl.height / 2)
		return (test_bot(cyl, ray, dist, y2));
	return (0);
}
