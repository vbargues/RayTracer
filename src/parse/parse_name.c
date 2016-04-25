/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:30:23 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:30:25 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*parse_name(int fd)
{
	char	**line;
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = 0;
	ret = (char *)malloc(sizeof(char) * 45);
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	while ((*line)[i] && (*line)[i] == 9)
		i++;
	while ((*line)[i] && (*line)[i] != '\n')
		ret[j++] = (*line)[i++];
	ret[j] = '\0';
	return (ret);
}
