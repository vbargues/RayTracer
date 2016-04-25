/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:29:15 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:29:16 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_point		parse_coord(int fd)
{
	t_point	point;
	char	**line;
	float	ret;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	ret = ft_stof(*line);
	point.x = ret;
	get_next_line(fd, line);
	ret = ft_stof(*line);
	point.y = ret;
	get_next_line(fd, line);
	ret = ft_stof(*line);
	point.z = ret;
	return (point);
}
