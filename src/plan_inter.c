/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:07 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:50:08 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

static int	plan_inter(t_plan plan, t_vector ray, double *dist)
{
	double		tmp;
	double		plop;

	plop = plan.a * ray.dir.x + plan.b * ray.dir.y + plan.c * ray.dir.z;
	if (fabs(plop) < 0.01f)
		return (0);
	tmp = -(plan.a * ray.origin.x + plan.b * ray.origin.y + plan.c *
			ray.origin.z + plan.d) / plop;
	if (tmp > 0.1 && (tmp < *dist || *dist < 0))
	{
		*dist = tmp;
		return (1);
	}
	return (0);
}

int			call_plan(t_obj obj, t_vector ray, double *dist)
{
	return (plan_inter(*(t_plan *)(obj.obj), ray, dist));
}
