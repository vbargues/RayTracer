/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:31:42 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:31:58 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <mlx.h>

t_img		*parse_texture(int fd)
{
	t_img		*img;
	char		**line;

	img = (t_img *)malloc(sizeof(t_img));
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	while (**line < 33)
		(*line)++;
	img->name = *line;
	if (open(img->name, O_RDONLY) <= 0)
	{
		ft_putendl("Error texture missing.");
		exit(0);
	}
	return (img);
}
