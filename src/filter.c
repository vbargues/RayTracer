/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:32:57 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:32:58 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int			filter(t_color c, t_win *win)
{
	int		i;

	i = (c.red + c.green + c.blue) / 3;
	if (win->filter == BLACK_WHITE)
		return (int_color(new_color(i, i, i)));
	if (win->filter == SEPIA)
	{
		return (int_color(new_color(c.red * 0.393 + c.blue * 0.189 + c.green
			* 0.769, c.red * 0.272 + c.blue * 0.131 + c.green * 0.534, c.red
			* 0.349 + c.blue * 0.168 + c.green * 0.686)));
	}
	if (win->filter == RED)
		return (int_color(new_color(255, i, i)));
	if (win->filter == BLUE)
		return (int_color(new_color(i, 255, i)));
	if (win->filter == GREEN)
		return (int_color(new_color(i, i, 255)));
	if (win->filter == NEG)
	{
		return (int_color(new_color(255 - c.red,
			255 - c.blue, 255 - c.green)));
	}
	return (int_color(c));
}
