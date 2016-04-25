/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:29:22 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:29:23 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			parse_cylinder_2(t_cylinder *cylinder)
{
	cylinder->top = new_point(0, -cylinder->height / 2, 0);
	cylinder->top = rot_point(cylinder->top, cylinder->rot.m16);
	cylinder->top = new_point(cylinder->top.x + cylinder->center.x,
		cylinder->top.y + cylinder->center.y, cylinder->top.z +
		cylinder->center.z);
	cylinder->bot = new_point(cylinder->center.x * 2 - cylinder->top.x,
		cylinder->center.y * 2 - cylinder->top.y, cylinder->center.z * 2 -
		cylinder->top.z);
}

t_cylinder		*parse_cylinder(int fd)
{
	t_cylinder	*cylinder;
	int			i;
	char		**line;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((i = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && strncmp(*line + i, "coord", 5) == 0)
			cylinder->center = parse_coord(fd);
		else if ((*line)[i] && strncmp(*line + i, "radius", 6) == 0)
			cylinder->radius = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "rot", 3) == 0)
			cylinder->rot = parse_rotation(fd);
		else if ((*line)[i] && strncmp(*line + i, "height", 6) == 0)
			cylinder->height = parse_height(fd);
	}
	parse_cylinder_2(cylinder);
	return (cylinder);
}
