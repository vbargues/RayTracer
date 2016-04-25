/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:18:23 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/10 16:18:31 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	size;

	if (!dest || !src)
		return (dest);
	size = ft_strlen(src);
	if (size >= n)
		ft_memcpy(dest, src, n);
	else
	{
		ft_memcpy(dest, src, size);
		ft_memset(dest + size, '\0', n - size);
	}
	return (dest);
}
