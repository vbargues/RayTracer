/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:37:53 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:37:57 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void			*ret_plan(t_plan *plan)
{
	void			*void_plan;

	void_plan = (void *)plan;
	return (void_plan);
}

void				create_plan(t_obj *object, int fd)
{
	object->normal = call_normal_plan;
	object->fonc = call_plan;
	object->texturing = texture_plan;
	object->obj = ret_plan(parse_plan(fd));
}
