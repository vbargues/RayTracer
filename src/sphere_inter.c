/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:47 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:50:49 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static float	ft_delta(t_sphere sph, t_vector ray, float *t1, float *t2)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = 2 * (ray.dir.x * (ray.origin.x - sph.center.x) +
		ray.dir.y * (ray.origin.y - sph.center.y) +
		ray.dir.z * (ray.origin.z - sph.center.z));
	c = (pow(ray.origin.x - sph.center.x, 2) + pow(ray.origin.y -
		sph.center.y, 2) + pow(ray.origin.z - sph.center.z, 2)) -
		pow(sph.radius, 2);
	delta = pow(b, 2) - 4 * a * c;
	*t1 = (-b - sqrt(delta)) / (2 * a);
	*t2 = (-b + sqrt(delta)) / (2 * a);
	return (delta);
}

static int		sphere_inter(t_sphere sph, t_vector ray, double *dist)
{
	float	delta;
	float	t1;
	float	t2;
	int		retval;

	retval = 0;
	delta = ft_delta(sph, ray, &t1, &t2);
	if (delta < 0)
		return (0);
	if (t1 > 0.1 && (t1 < *dist || *dist < 0))
	{
		*dist = (float)t1;
		retval = 1;
	}
	if (t2 > 0.1 && (t2 < *dist || *dist < 0))
	{
		*dist = (float)t2;
		retval = 1;
	}
	return (retval);
}

int				call_sphere(t_obj obj, t_vector ray, double *dist)
{
	return (sphere_inter(*(t_sphere *)(obj.obj), ray, dist));
}
