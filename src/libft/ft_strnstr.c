/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:51:14 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 18:05:51 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s2 || s2[0] == '\0')
		return ((char*)s1);
	if (!s1)
		return (NULL);
	while (*s1 && n--)
	{
		i = 0;
		while (s1[i] == s2[i] && i <= n)
			if (!s2[++i])
				return ((char*)s1);
		s1++;
	}
	return (NULL);
}
