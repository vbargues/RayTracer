/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:47:24 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/14 21:45:31 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t destlen;
	size_t srclen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	if (destlen >= size || !dst || !src || !size)
		return (srclen + size);
	ft_strncat(dst, src, size - destlen - 1);
	return (destlen + srclen);
}
