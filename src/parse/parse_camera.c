/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:28:55 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:28:59 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_cam		parse_camera(int fd)
{
	t_cam	camera;
	char	**line;
	int		i;
	int		ret;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((ret = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && (*line)[i] == 'o')
			camera.pos = parse_coord(fd);
		else if ((*line)[i] && (*line)[i] == 'r')
			camera.rot = parse_rotation(fd);
		else if ((*line)[i] && (*line)[i] == 'd')
			camera.screen.dist = (int)parse_distance(fd);
		else if ((*line)[i] && (*line)[i] == 'f')
			camera.focale = parse_focal(fd);
	}
	return (camera);
}
