/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:32:49 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:32:51 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

static t_color	new_plop(float red, float blue, float green)
{
	t_color		color;

	color.red = red;
	color.blue = blue;
	color.green = green;
	return (color);
}

static t_color	convert_color(int color)
{
	int			red;
	int			green;
	int			blue;

	red = (color & 0xFF0000) >> 16;
	green = (color & 0x00FF00) >> 8;
	blue = (color & 0xFF);
	return (new_color(red, blue, green));
}

static t_color	get_average_color(int **tab, int i, int j)
{
	t_color		ret;
	t_color		tmp;

	ret = new_color(0, 0, 0);
	tmp = convert_color(tab[i][j]);
	ret = new_plop(ret.red + tmp.red, ret.blue + tmp.blue, ret.green +
		tmp.green);
	tmp = convert_color(tab[i + 1][j]);
	ret = new_plop(ret.red + tmp.red, ret.blue + tmp.blue, ret.green +
		tmp.green);
	tmp = convert_color(tab[i][j + 1]);
	ret = new_plop(ret.red + tmp.red, ret.blue + tmp.blue, ret.green +
		tmp.green);
	tmp = convert_color(tab[i + 1][j + 1]);
	ret = new_plop(ret.red + tmp.red, ret.blue + tmp.blue, ret.green +
		tmp.green);
	ret = new_color(ret.red / 4, ret.blue / 4, ret.green / 4);
	return (ret);
}

void			get_image(t_win *win)
{
	int			i;
	int			j;

	j = 0;
	while (j < win->width * 2)
	{
		i = 0;
		while (i < win->height * 2)
		{
			adapt_pixel_in_image(win,
				filter(get_average_color(win->tab, i, j), win),
				j / 2, i / 2);
			i += 2;
		}
		j += 2;
	}
}
