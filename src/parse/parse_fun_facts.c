/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fun_facts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:29:51 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:29:51 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		**parse_fun_facts(void)
{
	char	**line;
	int		ret;
	int		i;
	int		fd;

	fd = 0;
	i = 0;
	line = (char **)malloc(sizeof(char *) * 70);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if ((fd = open("src/parse/fun_facts", O_RDONLY)) < 0)
	{
		ft_putstr("Erreur, fun facts introuvable\n");
		exit(0);
	}
	while ((ret = get_next_line(fd, line + i)) > 0)
		i++;
	return (line);
}
