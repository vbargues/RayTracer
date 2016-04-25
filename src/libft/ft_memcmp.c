/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:48:02 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/05 14:05:50 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *d1;
	const unsigned char *d2;

	d1 = s1;
	d2 = s2;
	if (n != 0)
		while (n--)
			if (*(d1++) != *(d2++))
				return (*(--d1) - *(--d2));
	return (0);
}
