/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:31:36 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/19 13:21:57 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_sphere		*parse_sphere(int fd)
{
	t_sphere	*sphere;
	int			i;
	char		**line;
	int			ret;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((ret = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && strncmp(*line + i, "coord", 5) == 0)
			sphere->center = parse_coord(fd);
		else if ((*line)[i] && strncmp(*line + i, "radius", 6) == 0)
			sphere->radius = parse_radius(fd);
	}
	return (sphere);
}
