/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <lsalomme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:31:53 by lsalomme          #+#    #+#             */
/*   Updated: 2015/12/05 17:01:39 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include "parse/gnl/libft/includes/libft.h"
#include <mlx.h>

int		expose_hook(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (0);
}

int		loop_hook(t_win *win)
{
	if (win->escape_pressed)
		key_hook(win);
	return (0);
}

int		main(int argc, char **argv)
{
	t_win	win;

	win.mlx = mlx_init();
	win.fdf = 0;
	if (argc == 3 && strcmp(argv[2], "fdf") == 0)
		win.fdf = 1;
	if (!win.mlx || (argc != 2 && win.fdf == 0))
		return (0);
	params_init(&win, argv[1]);
	win.win = mlx_new_window(win.mlx, win.width, win.height, win.name);
	mlx_expose_hook(win.win, expose_hook, &win);
	call_thread(&win);
	mlx_do_key_autorepeatoff(win.mlx);
	mlx_hook(win.win, KEYPRESS, KEYPRESSMASK, key_press, &win);
	mlx_hook(win.win, KEYRELEASE, KEYRELEASEMASK, key_release, &win);
	mlx_loop_hook(win.mlx, loop_hook, &win);
	expose_hook(&win);
	mlx_loop(win.mlx);
	return (1);
}
