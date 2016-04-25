/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:39:00 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:39:01 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"

t_llst		*ft_parse_llstnew(t_light *light)
{
	t_llst	*new_light;

	new_light = (t_llst *)malloc(sizeof(new_light));
	if (new_light == (t_llst *)NULL)
		return (NULL);
	new_light->light = light;
	new_light->next = NULL;
	return (new_light);
}
