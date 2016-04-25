/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:39:07 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:39:07 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"

t_lst		*ft_parse_lstnew(t_obj *object)
{
	t_lst	*new_obj;

	new_obj = (t_lst *)malloc(sizeof(new_obj));
	if (new_obj == (t_lst *)NULL)
		return (NULL);
	new_obj->obj = object;
	new_obj->next = NULL;
	return (new_obj);
}
