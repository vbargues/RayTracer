/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:45:00 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/17 19:58:39 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char		*cpy;
	size_t		len;
	size_t		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	cpy = (char *)malloc(sizeof(cpy) * len + 1);
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
