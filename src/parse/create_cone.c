/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:37:24 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:37:26 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	*ret_cone(t_cone *cone)
{
	void			*void_cone;

	void_cone = (void *)cone;
	return (void_cone);
}

void		create_cone(t_obj *object, int fd)
{
	object->normal = call_normal_cone;
	object->fonc = call_cone;
	object->texturing = no_texture;
	object->obj = ret_cone(parse_cone(fd));
}
