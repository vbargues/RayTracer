/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <lsalomme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:22:21 by lsalomme          #+#    #+#             */
/*   Updated: 2015/12/05 16:52:59 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include <stdlib.h>
#define LINE ((i % 4) * nb_line + line + 1)

static	t_color	get_color(t_scene scene, t_vector ray, t_obj obj, t_point inter)
{
	t_color		save;
	t_color		ret;

	scene.refl = 1;
	scene.depth = MAX_DEPTH;
	save = get_first_ray(scene, ray, obj, inter);
	ret = get_ambiant_light(scene, ray, obj, inter);
	return (new_color(save.red + ret.red, save.blue + ret.blue,
		save.green + ret.green));
}

static void		for_each_column(t_win *win, int i, int j, t_point p3)
{
	t_vector	ray;
	t_obj		int_obj;
	t_point		inter;
	double		dist;

	dist = -1;
	ray.origin = new_point(win->scene.camera.pos.x, win->scene.camera.pos.y,
			win->scene.camera.pos.z);
	ray.dir = vec_dir(win->scene.camera.pos, p3);
	if (find_closest_inter(win->scene.lst_obj, &int_obj, &dist, ray) >= 0)
	{
		win->scene.refl = 1;
		win->scene.depth = MAX_DEPTH;
		inter = new_point(ray.origin.x + dist * ray.dir.x, ray.origin.y +
			dist * ray.dir.y, ray.origin.z + dist * ray.dir.z);
		win->tab[i][j] = int_color(get_color(win->scene, ray,
											int_obj, inter));
	}
}

static void		for_each_line(t_win *win, int i, t_point p1, t_point p2)
{
	int			j;
	t_point		p3;

	j = -1;
	while (++j < win->width * 2)
	{
		p3 = new_point((p2.x - p1.x) * (j + 1) / ((double)win->width * 2) +
			p1.x, (p2.y - p1.y) * (j + 1) / ((double)win->width * 2) + p1.y,
			(p2.z - p1.z) * (j + 1) / ((double)win->width * 2) + p1.z);
		for_each_column(win, i, j, p3);
	}
	if (i % 2 == 0)
		win->calc_line[i / 2] = 1;
}

static void		render(t_win *win, int nb_line, int i)
{
	int		line;

	line = -1;
	while (++line < nb_line && ((++i % 4) * nb_line + line) < win->height * 2)
	{
		for_each_line(win, ((i % 4) * nb_line + line),
			new_point((win->scene.camera.screen.bot_left.x -
			win->scene.camera.screen.top_left.x) * LINE
			/ ((double)win->height * 2) + win->scene.camera.screen.top_left.x,
			(win->scene.camera.screen.bot_left.y -
			win->scene.camera.screen.top_left.y) * LINE
			/ ((double)win->height * 2) + win->scene.camera.screen.top_left.y,
			(win->scene.camera.screen.bot_left.z -
			win->scene.camera.screen.top_left.z) * LINE
			/ ((double)win->height * 2) + win->scene.camera.screen.top_left.z),
			new_point((win->scene.camera.screen.bot_right.x -
			win->scene.camera.screen.top_right.x) * LINE
			/ ((double)win->height * 2) + win->scene.camera.screen.top_right.x,
			(win->scene.camera.screen.bot_right.y -
			win->scene.camera.screen.top_right.y) * LINE
			/ ((double)win->height * 2) + win->scene.camera.screen.top_right.y,
			(win->scene.camera.screen.bot_right.z -
			win->scene.camera.screen.top_right.z) * LINE /
			((double)win->height * 2) + win->scene.camera.screen.top_right.z));
	}
}

void			*call_render(void *wiin)
{
	int			i;
	pthread_t	thread;
	t_win		*win;

	win = (t_win *)wiin;
	i = -1;
	thread = pthread_self();
	while (!(pthread_equal(thread, win->threads[++i])))
		;
	render(win, win->line_thread, i);
	return (NULL);
}
