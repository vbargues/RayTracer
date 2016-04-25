/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:38:23 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:38:24 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void			*ret_sphere(t_sphere *sphere)
{
	void			*void_sphere;

	void_sphere = (void *)sphere;
	return (void_sphere);
}

void				create_sphere(t_obj *object, int fd)
{
	object->normal = call_normal_sphere;
	object->fonc = call_sphere;
	object->texturing = texture_sphere;
	object->obj = ret_sphere(parse_sphere(fd));
}
