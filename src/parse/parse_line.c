/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:46:33 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:46:34 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		parse_line(t_win *win, char **line, int i, int fd)
{
	if ((*line)[i] && (*line[i]) == 'n')
		win->name = parse_name(fd);
	else if ((*line)[i] && (*line[i]) == 'f')
		win->filter = parse_filter(fd);
	else if ((*line)[i] && (*line[i]) == 'r')
		*win = parse_render(*win, fd);
	else if ((*line)[i] && (*line[i]) == 'c')
		win->scene.camera = parse_camera(fd);
}
