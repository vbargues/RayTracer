/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:31:16 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:31:17 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_win	parse_render(t_win win, int fd)
{
	char	**line;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	get_next_line(fd, line);
	win.width = ft_atoi(*line);
	get_next_line(fd, line);
	win.height = ft_atoi(*line);
	return (win);
}
