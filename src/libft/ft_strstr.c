/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:06:23 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/10 15:50:10 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int j;

	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		j = 0;
		while (s1[j] == s2[j])
			if (!s2[++j])
				return ((char *)s1);
		s1++;
	}
	return (NULL);
}
