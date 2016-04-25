/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:31:01 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:31:02 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_plan_coord(t_plan *plan, int fd, char **line)
{
	get_next_line(fd, line);
	plan->a = ft_stof(*line);
	get_next_line(fd, line);
	plan->b = ft_stof(*line);
	get_next_line(fd, line);
	plan->c = ft_stof(*line);
	get_next_line(fd, line);
	plan->d = ft_stof(*line);
}

static void	init(t_plan *plan)
{
	plan->def.x = 0.0;
	plan->def.y = 0.0;
	plan->def.z = 0.0;
}

t_plan		*parse_plan(int fd)
{
	t_plan	*plan;
	char	**line;
	int		i;
	int		ret;

	plan = (t_plan *)malloc(sizeof(t_plan));
	init(plan);
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((ret = get_next_line(fd, line)) > 0 && (*line)[0] != '}')
	{
		i = 0;
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && strncmp(*line + i, "coord", 5) == 0)
			parse_plan_coord(plan, fd, line);
		else if (!strncmp(*line + i, "def", 3))
			plan->def = parse_coord(fd);
	}
	return (plan);
}
