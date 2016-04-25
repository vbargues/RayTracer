/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:49:07 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/12 17:12:27 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	ret = (char *)malloc(sizeof(ret) * len + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[start + i];
	ret[i] = '\0';
	return (ret);
}
