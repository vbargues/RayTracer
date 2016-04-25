/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:30:18 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:30:18 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_light			*parse_light(int fd)
{
	t_light		*light;
	char		**line;
	int			ret;
	int			i;

	light = (t_light *)malloc(sizeof(t_light));
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((ret = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && (*line)[i] == 'c')
			light->color = parse_color(fd);
		else if ((*line)[i] && (*line)[i] == 'i')
			light->intensity = parse_intensity(fd);
		else if ((*line)[i] && (*line)[i] == 's')
			light->body = *(parse_sphere(fd));
	}
	return (light);
}
