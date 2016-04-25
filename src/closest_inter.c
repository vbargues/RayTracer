/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:48:32 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:33 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <stdlib.h>

double		find_closest_inter(t_lst *ptr_lst, t_obj *obj_ptr, double *dist,
							t_vector ray)
{
	if (ptr_lst == NULL)
		return (*dist);
	if ((*ptr_lst->obj->fonc)(*(ptr_lst->obj), ray, dist))
		*obj_ptr = *(ptr_lst->obj);
	return (find_closest_inter(ptr_lst->next, obj_ptr, dist, ray));
}
