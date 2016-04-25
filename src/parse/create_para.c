/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_para.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:37:44 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:37:46 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	*ret_para(t_para *para)
{
	void			*void_para;

	void_para = (void *)para;
	return (void_para);
}

void		create_para(t_obj *object, int fd)
{
	object->normal = call_normal_para;
	object->fonc = call_para;
	object->texturing = no_texture;
	object->obj = ret_para(parse_para(fd));
}
