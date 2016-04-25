/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:44:45 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 18:21:58 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static char		*make_it_a_str(char c)
{
	char *ret;

	ret = (char *)malloc(sizeof(char) + 1);
	if (!ret)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

static char		*new_join(const char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	if (s2)
		free(s2);
	return (new);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		nbis;

	if (n == 0)
	{
		ret = ft_strdup("0");
		if (!ret)
			return (NULL);
		return (ret);
	}
	nbis = n;
	if (n > 0)
		n = -n;
	ret = NULL;
	while (n != 0)
	{
		ret = new_join(make_it_a_str(48 - (n % 10)), ret);
		n = n / 10;
	}
	if (nbis < 0)
		ret = ft_strjoin(make_it_a_str('-'), ret);
	if (!ret)
		return (NULL);
	return (ret);
}
