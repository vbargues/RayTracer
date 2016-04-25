/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:38:46 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:38:49 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"

void		ft_parse_lstadd(t_lst **be_lst, t_lst *new_obj)
{
	if (!new_obj)
		return ;
	if (!be_lst)
		return ;
	new_obj->next = *be_lst;
	*be_lst = new_obj;
}
