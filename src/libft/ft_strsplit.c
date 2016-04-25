/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:15:05 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 17:31:53 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static unsigned int	nb_tab(char const *s, char c)
{
	int i;

	i = 0;
	if (*s != '\0' && *s != c)
		i++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			i++;
		s++;
	}
	return (i);
}

static char			*get_next_group(char const **s, char c)
{
	char			*ret;
	char			*found;
	unsigned int	size;

	while (**s == c)
		(*s)++;
	found = ft_strchr(*s, (int)c);
	if (found == NULL)
	{
		ret = ft_strdup(*s);
		return (ret);
	}
	else
	{
		size = found - *s;
		ret = (char *)malloc(sizeof(ret) * size + 1);
		if (!ret)
			return (NULL);
		ret = ft_strncpy(ret, *s, size);
		ret[size] = '\0';
		(*s) += size;
	}
	return (ret);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	nbtab;

	if (s == NULL)
		return (NULL);
	nbtab = nb_tab(s, c);
	tab = (char **)malloc(sizeof(tab) * nbtab + 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < nbtab)
		tab[i] = get_next_group(&s, c);
	tab[i] = NULL;
	if (ft_strequ(s, ""))
		tab[0] = NULL;
	return (tab);
}
