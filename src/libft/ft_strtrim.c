/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:02:13 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 17:37:03 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		is_blank_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	eco;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	while (is_blank_space(s[i]))
		i++;
	if (i == slen)
		return (ft_strdup(""));
	eco = slen - 1;
	while (is_blank_space(s[slen - j - 1]))
		j++;
	eco = slen - j - i;
	ret = (char *)malloc(sizeof(ret) * (eco) + 1);
	if (!ret)
		return (NULL);
	ret = ft_strsub(s, i, eco);
	return (ret);
}
