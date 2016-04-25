/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:29:08 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:29:09 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_color		parse_color(int fd)
{
	char	**line;
	t_color	color;
	float	ret;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	ret = ft_stof(*line);
	color.red = ret;
	get_next_line(fd, line);
	ret = ft_stof(*line);
	color.green = ret;
	get_next_line(fd, line);
	ret = ft_stof(*line);
	color.blue = ret;
	return (color);
}
