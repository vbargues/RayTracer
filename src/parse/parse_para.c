/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_para.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:30:53 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:30:55 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_para			*parse_para(int fd)
{
	t_para		*c;
	int			i;
	char		**line;

	c = (t_para *)malloc(sizeof(t_para));
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((i = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] == 'c' && (*line)[i + 1] == 'o' && (*line)[i + 2] == 'o')
			c->center = parse_coord(fd);
		else if ((*line)[i] == 'a')
			c->a = parse_radius(fd);
		else if ((*line)[i] == 'b')
			c->b = parse_radius(fd);
		else if ((*line)[i] == 'r' && (*line)[i + 1] == 'o')
			c->rot = parse_rotation(fd);
	}
	return (c);
}
