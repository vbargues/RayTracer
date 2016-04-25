/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:33:43 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:33:44 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>
#include <stdlib.h>

void			call_thread(t_win *win)
{
	int			i;
	void		**shit;
	int			j;

	j = 0;
	shit = NULL;
	i = fmin(NB_THREAD, win->height * 2);
	win->threads = (pthread_t *)malloc(sizeof(pthread_t) * i);
	win->line_ind = 0;
	win->line_thread = floor(win->height * 2.0f / NB_THREAD);
	while (--i >= 0)
		pthread_create(&(win->threads[i]), NULL, call_render, (void *)win);
	i = fmin(NB_THREAD, win->height * 2);
	while (j == 0)
		j = display(win);
	while (i-- >= 0)
		pthread_join(win->threads[i], shit);
	get_image(win);
	if (win->fdf)
		map_fdf(win);
}
