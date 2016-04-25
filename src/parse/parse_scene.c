/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:31:29 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:31:30 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_lst	**malloc_lst(void)
{
	t_lst		**begin_lst;

	begin_lst = (t_lst **)malloc(sizeof(t_lst *));
	*begin_lst = (t_lst *)malloc(sizeof(t_lst));
	*begin_lst = NULL;
	return (begin_lst);
}

static t_llst	**malloc_llst(void)
{
	t_llst		**begin_llst;

	begin_llst = (t_llst **)malloc(sizeof(t_llst *));
	*begin_llst = (t_llst *)malloc(sizeof(t_llst));
	*begin_llst = NULL;
	return (begin_llst);
}

static void		parse_object_stat(t_obj *object, t_lst **begin_lst)
{
	if (!(*begin_lst))
		*begin_lst = ft_parse_lstnew(object);
	else
		ft_parse_lstadd(begin_lst, ft_parse_lstnew(object));
}

static void		parse_light_stat(t_light *light, t_llst **begin_llst)
{
	if (!(*begin_llst))
		*begin_llst = ft_parse_llstnew(light);
	else
		ft_parse_llstadd(begin_llst, ft_parse_llstnew(light));
}

void			parse_scene(int fd, t_win *win)
{
	char		**line;
	int			i;
	t_lst		**begin_lst;
	t_llst		**begin_llst;
	int			id;

	id = 0;
	begin_lst = malloc_lst();
	begin_llst = malloc_llst();
	line = malloc_ppchar();
	while (get_next_line(fd, line) > 0 && (*line)[0] != '}' && !(i = 0))
	{
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		parse_line(win, line, i, fd);
		if ((*line)[i] && (*line)[i] == 'o')
			parse_object_stat(parse_object(fd, id++), begin_lst);
		else if ((*line)[i] && (*line)[i] == 'l')
			parse_light_stat(parse_light(fd), begin_llst);
	}
	win->scene.lst_obj = *begin_lst;
	win->scene.lst_light = *begin_llst;
}
