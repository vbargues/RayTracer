/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:28:41 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:32:07 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

float		parse_brightness(int fd)
{
	float	brightness;
	char	**line;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	brightness = ft_stof(*line);
	return (brightness);
}
