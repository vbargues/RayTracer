/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <lsalomme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:48:10 by lsalomme          #+#    #+#             */
/*   Updated: 2015/11/24 14:48:13 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <mlx.h>
#include <stdlib.h>

int		key_press(int keycode, t_win *win)
{
	if (keycode == 53)
		win->escape_pressed = 1;
	return (0);
}

int		key_release(int keycode, t_win *win)
{
	if (keycode == 53)
		win->escape_pressed = 0;
	return (0);
}

int		key_hook(t_win *win)
{
	if (win->escape_pressed)
		exit(0);
	return (0);
}
