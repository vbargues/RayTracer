/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:48:13 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:16 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int				call_cylinder(t_obj obj, t_vector ray, double *dist)
{
	return (cylinder_inter(*(t_cylinder *)(obj.obj), ray, dist));
}
