/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:31:06 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:31:07 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include "parse/parse.h"

static void	corners_init2(t_screen *screen, t_scene scene, t_point dir_screen)
{
	screen->top_right.x = (screen->width / 2 - 1) * scene.camera.focale;
	screen->top_right.y = -(screen->height / 2) * scene.camera.focale;
	screen->top_right.z = 0;
	screen->top_right = rot_point(screen->top_right, scene.camera.rot.m16);
	screen->top_right.x += scene.camera.pos.x + dir_screen.x * screen->dist;
	screen->top_right.y += scene.camera.pos.y + dir_screen.y * screen->dist;
	screen->top_right.z += scene.camera.pos.z + dir_screen.z * screen->dist;
	screen->top_left.x = -(screen->width / 2) * scene.camera.focale;
	screen->top_left.y = -screen->height / 2 * scene.camera.focale;
	screen->top_left.z = 0;
	screen->top_left = rot_point(screen->top_left, scene.camera.rot.m16);
	screen->top_left.x += scene.camera.pos.x + dir_screen.x * screen->dist;
	screen->top_left.y += scene.camera.pos.y + dir_screen.y * screen->dist;
	screen->top_left.z += scene.camera.pos.z + dir_screen.z * screen->dist;
}

static void	corners_init(t_screen *screen, t_scene scene)
{
	t_point	dir_screen;

	dir_screen = rot_point(new_point(0, 0, 1), scene.camera.rot.m16);
	corners_init2(screen, scene, dir_screen);
	screen->bot_right.x = (screen->width / 2 - 1) * scene.camera.focale;
	screen->bot_right.y = (screen->height / 2 - 1) * scene.camera.focale;
	screen->bot_right.z = 0;
	screen->bot_right = rot_point(screen->bot_right, scene.camera.rot.m16);
	screen->bot_right.x += scene.camera.pos.x + dir_screen.x * screen->dist;
	screen->bot_right.y += scene.camera.pos.y + dir_screen.y * screen->dist;
	screen->bot_right.z += scene.camera.pos.z + dir_screen.z * screen->dist;
	screen->bot_left.x = -screen->width / 2 * scene.camera.focale;
	screen->bot_left.y = (screen->height / 2 - 1) * scene.camera.focale;
	screen->bot_left.z = 0;
	screen->bot_left = rot_point(screen->bot_left, scene.camera.rot.m16);
	screen->bot_left.x += scene.camera.pos.x + dir_screen.x * screen->dist;
	screen->bot_left.y += scene.camera.pos.y + dir_screen.y * screen->dist;
	screen->bot_left.z += scene.camera.pos.z + dir_screen.z * screen->dist;
}

static void	parsing(t_win *win, char *file)
{
	int		fd;

	win->fun_facts = parse_fun_facts();
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr("Erreur, fichier introuvable\n");
		exit(0);
	}
	parse_scene(fd, win);
	if ((fd = close(fd)) < 0)
	{
		ft_putstr("Erreur close\n");
		exit(0);
	}
	texture(win);
	normal_map(win);
}

void		params_init(t_win *win, char *file)
{
	int		i;

	i = -1;
	srand(time(NULL));
	parsing(win, file);
	win->escape_pressed = 0;
	win->img.height = win->height;
	win->img.width = win->width;
	win->img.img = mlx_new_image(win->mlx, win->width, win->height);
	win->calc_line = ft_strnew(win->height);
	if (!win->img.img)
		exit(0);
	win->img.data = mlx_get_data_addr(win->img.img, &(win->img.bpp),
									&(win->img.sl), &(win->img.endian));
	win->scene.camera.screen.height = win->height;
	win->scene.camera.screen.width = win->width;
	corners_init(&(win->scene.camera.screen), win->scene);
	win->tab = (int **)malloc(sizeof(int*) * win->height * 2);
	while (++i < (win->height * 2))
		win->tab[i] = (int *)malloc(sizeof(int) * win->width * 2);
}
