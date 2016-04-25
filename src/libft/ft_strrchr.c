/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:02:57 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/13 18:35:44 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int ch)
{
	char *save;

	save = NULL;
	if (str == NULL)
		return (save);
	while (*str)
	{
		if (*str == (char)ch)
			save = (char *)str;
		str++;
	}
	if (!(char)ch)
		save = (char *)str;
	return (save);
}
