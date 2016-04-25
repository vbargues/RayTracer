/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:32:30 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:32:35 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_cone			*parse_cone(int fd)
{
	t_cone		*c;
	int			i;
	char		**line;

	c = (t_cone *)malloc(sizeof(t_cone));
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((i = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && strncmp(*line + i, "coord", 5) == 0)
			c->center = parse_coord(fd);
		else if ((*line)[i] && strncmp(*line + i, "angle", 5) == 0)
			c->angle = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "bot", 3) == 0)
			c->bot = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "top", 3) == 0)
			c->top = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "rot", 3) == 0)
			c->rot = parse_rotation(fd);
	}
	c->dir = rot_point(new_point(0, -1, 0), c->rot.m16);
	return (c);
}
