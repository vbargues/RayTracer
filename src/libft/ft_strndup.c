/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:27:28 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/17 18:55:57 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	result = (char *)malloc(sizeof(result) * len + 1);
	if (!result)
		return (0);
	result[len] = '\0';
	return ((char *)ft_memcpy(result, s, len));
}
