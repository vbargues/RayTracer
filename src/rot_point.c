/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:25 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:51:37 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include <stdlib.h>

t_point			rot_point(t_point point, float *m16)
{
	t_point		new_point;
	float		*m4;

	m4 = (float *)malloc(sizeof(float) * 4);
	m4[0] = point.x;
	m4[1] = point.y;
	m4[2] = point.z;
	m4 = prod_mat(m4, m16);
	new_point.x = m4[0];
	new_point.y = m4[1];
	new_point.z = m4[2];
	if (m4)
		free(m4);
	return (new_point);
}
