/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:29:32 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:29:34 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <mlx.h>

void	texture(t_win *win)
{
	t_lst *tmp;

	tmp = win->scene.lst_obj;
	while (tmp)
	{
		if (tmp->obj->texture)
		{
			tmp->obj->texture->img = mlx_xpm_file_to_image(
			win->mlx, tmp->obj->texture->name,
			&(tmp->obj->texture->width), &(tmp->obj->texture->height));
			tmp->obj->texture->data = mlx_get_data_addr(tmp->obj->texture->img,
				&(tmp->obj->texture->bpp), &(tmp->obj->texture->sl),
				&(tmp->obj->texture->endian));
		}
		tmp = tmp->next;
	}
}
