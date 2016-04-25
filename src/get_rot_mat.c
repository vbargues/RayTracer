/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:48:46 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:47 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

float	*get_rot_mat(float a, float b, float c)
{
	float		*tab;

	tab = (float *)malloc(sizeof(tab) * 16);
	if (!tab)
		return (NULL);
	tab[0] = cos(b) * cos(c);
	tab[1] = -cos(b) * sin(c);
	tab[2] = sin(b);
	tab[3] = 0;
	tab[4] = sin(a) * sin(b) * cos(c) + cos(a) * sin(c);
	tab[5] = -sin(a) * sin(b) * sin(c) + cos(a) * cos(c);
	tab[6] = -sin(a) * cos(b);
	tab[7] = 0;
	tab[8] = -cos(a) * sin(b) * cos(c) + sin(a) * sin(c);
	tab[9] = cos(a) * sin(b) * sin(c) + sin(a) * cos(c);
	tab[10] = cos(a) * cos(b);
	tab[11] = 0;
	tab[12] = 0;
	tab[13] = 0;
	tab[14] = 0;
	tab[15] = 1;
	return (tab);
}
