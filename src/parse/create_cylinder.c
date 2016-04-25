/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:37:33 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:37:35 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void			*ret_cylinder(t_cylinder *cylinder)
{
	void			*void_cylinder;

	void_cylinder = (void *)cylinder;
	return (void_cylinder);
}

void				create_cylinder(t_obj *object, int fd)
{
	object->normal = call_normal_cylinder;
	object->fonc = call_cylinder;
	object->texturing = no_texture;
	object->obj = ret_cylinder(parse_cylinder(fd));
}
