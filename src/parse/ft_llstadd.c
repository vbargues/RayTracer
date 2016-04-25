/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:38:11 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:38:13 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"

void	ft_parse_llstadd(t_llst **be_lst, t_llst *new_light)
{
	new_light->next = *be_lst;
	*be_lst = new_light;
}
