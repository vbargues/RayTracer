/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:19:49 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/12 15:23:54 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(ret) * size + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i <= size)
		ret[i++] = '\0';
	return (ret);
}
