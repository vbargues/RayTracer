/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:04:06 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 18:12:01 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	cpy = (char *)malloc(len);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, src, len);
	while (i < len)
	{
		((char *)dst)[i] = cpy[i];
		i++;
	}
	if (cpy)
		free(cpy);
	return (dst);
}
