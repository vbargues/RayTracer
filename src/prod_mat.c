/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:11 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:50:12 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

float	*prod_mat(float *m1, float *m2)
{
	int		i;
	int		j;
	float	*tab;

	tab = (float *)malloc(sizeof(tab) * 4);
	if (!tab)
		return (0);
	i = -1;
	while (++i < 4)
	{
		tab[i] = 0;
		j = -1;
		while (++j < 4)
			tab[i] += m1[j] * m2[4 * j + i];
	}
	if (m1)
		free(m1);
	return (tab);
}
