/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:32:41 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:32:42 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <mlx.h>

static int	loading(float nb_line, t_win *win)
{
	int		x;
	int		y;
	float	nb;

	nb = nb_line / win->height * 100;
	x = win->width / 2 - 200;
	y = win->height / 2;
	while (y <= win->height / 2 + 20)
	{
		while (x < win->width / 2 + 200)
		{
			if (y == win->height / 2 || y == win->height / 2 + 20)
				adapt_pixel_in_image(win, 16777215, x, y);
			if (x > win->width / 2 - 200 && x < win->width / 2 + 200 && x % 10)
				if (nb > 0 && y != win->height / 2 && y < win->height / 2 + 19)
					if (x < (win->width / 2 - 200) + 400 * nb / 100)
						adapt_pixel_in_image(win, 0xD40028, x, y);
			x++;
		}
		x = win->width / 2 - 200;
		adapt_pixel_in_image(win, 16777215, x, y);
		adapt_pixel_in_image(win, 16777215, win->width / 2 + 200, y);
		y++;
	}
	return (0);
}

void		calc_line(t_win *win)
{
	int		i;
	int		cp;

	cp = 0;
	i = 0;
	while (i < win->height)
	{
		if (win->calc_line[i])
			cp++;
		i++;
	}
	loading(cp, win);
}
