/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:10:28 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/12 13:16:11 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = malloc(sizeof(ret) * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
