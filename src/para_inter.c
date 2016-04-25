/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:47:55 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:00 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static float	ft_delta(t_para para, t_vector *ray, float *r2, float *r1)
{
	float		a;
	float		b;
	float		c;
	float		delta;

	ray->origin = rot_point(new_point(ray->origin.x - para.center.x,
		ray->origin.y - para.center.y, ray->origin.z - para.center.z),
		para.rot.negm16);
	ray->dir = rot_point(ray->dir, para.rot.m16);
	a = pow(ray->dir.x, 2) / pow(para.a, 2) + pow(ray->dir.z, 2) /
	pow(para.b, 2);
	b = 2 * (ray->dir.x * ray->origin.x / pow(para.a, 2) +
		ray->dir.z * ray->origin.z / pow(para.b, 2)) - ray->dir.y;
	c = pow(ray->origin.x, 2) / pow(para.a, 2) - ray->origin.y +
	pow(ray->origin.z, 2) / pow(para.b, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta <= 0)
		return (-1);
	*r2 = (-b - sqrt(delta)) / (2 * a);
	*r1 = (-b + sqrt(delta)) / (2 * a);
	return (delta);
}

static int		para_inter(t_para para, t_vector ray, double *dist)
{
	float		delta;
	float		t1;
	float		t2;
	int			retval;

	retval = 0;
	delta = ft_delta(para, &ray, &t1, &t2);
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

int				call_para(t_obj obj, t_vector ray, double *dist)
{
	return (para_inter(*(t_para *)(obj.obj), ray, dist));
}
