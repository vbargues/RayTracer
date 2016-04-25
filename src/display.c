/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:34:00 by vbargues          #+#    #+#             */
/*   Updated: 2016/02/12 10:34:03 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

static int		dark(int color)
{
	t_color struc;

	struc = color_int(color);
	return (int_color(new_color(struc.red / 3, struc.blue / 3,
		struc.green / 3)));
}

static char		*get_fun_fact(t_win *win)
{
	return (win->fun_facts[rand() % 38]);
}

static int		lanorme(t_win *win)
{
	int			i;
	int			j;
	int			k;

	k = 1;
	j = -1;
	while (++j < win->height)
	{
		if (win->calc_line[j] && (i = -1))
		{
			while (++i < win->width)
			{
				if (j > win->height / 2 - 30 && j < win->height / 2 + 60 &&
					i > win->width / 2 - 350 && i < win->width / 2 + 350)
					adapt_pixel_in_image(win, dark(win->tab[j * 2][i * 2]),
						i, j);
				else
					adapt_pixel_in_image(win, win->tab[j * 2][i * 2], i, j);
			}
		}
		else
			k = 0;
	}
	mlx_do_sync(win->mlx);
	return (k);
}

int				display(t_win *win)
{
	static int	w = 0;
	static char	*fun_fact = NULL;

	calc_line(win);
	expose_hook(win);
	if (w % 8 < 2)
		mlx_string_put(win->mlx, win->win, win->width / 2 - 200,
			win->height / 2 - 25, 0xffffff, "Loading \n");
	else if (w % 8 < 4)
		mlx_string_put(win->mlx, win->win, win->width / 2 - 200,
			win->height / 2 - 25, 0xffffff, "Loading . \n");
	else if (w % 8 < 6)
		mlx_string_put(win->mlx, win->win, win->width / 2 - 200,
			win->height / 2 - 25, 0xffffff, "Loading .. \n");
	else if (w % 8 < 8)
		mlx_string_put(win->mlx, win->win, win->width / 2 - 200,
			win->height / 2 - 25, 0xffffff, "Loading ... \n");
	if (w % 40 == 0)
		fun_fact = get_fun_fact(win);
	mlx_string_put(win->mlx, win->win, win->width / 2 - 200,
		win->height / 2 + 25, 0xffffff, fun_fact);
	w++;
	return (lanorme(win));
}
