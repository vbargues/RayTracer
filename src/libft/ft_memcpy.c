/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:26:54 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/10 16:14:07 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest2;
	unsigned char	*src2;

	if (n == 0 || src == dst)
		return (dst);
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dst;
	i = -1;
	while (++i < n)
		dest2[i] = src2[i];
	return (dst);
}
