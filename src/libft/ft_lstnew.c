/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 15:07:03 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/14 17:33:28 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*new_content;

	new = (t_list *)malloc(sizeof(new));
	if (new == (t_list *)NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new_content = ft_memalloc(content_size);
	if (!new_content)
		return (NULL);
	new->content = ft_memcpy(new_content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
