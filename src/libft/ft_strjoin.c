/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:53:35 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 17:29:53 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(ret) * (len1 + len2) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len1)
		ret[i] = s1[i];
	while (++j < len2)
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	return (ret);
}
