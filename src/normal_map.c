/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:31:30 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:31:31 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <mlx.h>

void	normal_map(t_win *win)
{
	t_lst *tmp;

	tmp = win->scene.lst_obj;
	while (tmp)
	{
		if (tmp->obj->normal_map)
		{
			tmp->obj->normal_map->img = mlx_xpm_file_to_image(
			win->mlx, tmp->obj->normal_map->name,
			&(tmp->obj->normal_map->width), &(tmp->obj->normal_map->height));
			tmp->obj->normal_map->data = mlx_get_data_addr(
				tmp->obj->normal_map->img,
				&(tmp->obj->normal_map->bpp), &(tmp->obj->normal_map->sl),
				&(tmp->obj->normal_map->endian));
		}
		tmp = tmp->next;
	}
}
