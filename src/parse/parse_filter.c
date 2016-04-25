/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:29:36 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:29:37 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

enum e_filter		parse_filter(int fd)
{
	char	**line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	while ((*line)[i] && (*line)[i] == 9)
		i++;
	return (TEST);
	if (strncmp(*line + i, "sepia", 5) == 0)
		return (SEPIA);
	if (strncmp(*line + i, "black_white", 11) == 0)
		return (BLACK_WHITE);
	if (strncmp(*line + i, "red", 3) == 0)
		return (RED);
	if (strncmp(*line + i, "green", 5) == 0)
		return (GREEN);
	if (strncmp(*line + i, "blue", 4) == 0)
		return (BLUE);
	if (strncmp(*line + i, "neg", 3) == 0)
		return (NEG);
	return (NONE);
}
