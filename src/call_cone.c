/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:48:06 by vbargues          #+#    #+#             */
/*   Updated: 2016/02/11 17:33:50 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int		call_cone(t_obj obj, t_vector ray, double *dist)
{
	return (cone_inter(*(t_cone *)(obj.obj), ray, dist));
}
