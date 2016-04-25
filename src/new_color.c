/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:49:22 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:49:23 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_color			new_color(float red, float blue, float green)
{
	t_color	color;

	if (red > 255.0f)
		red = 255.0f;
	if (blue > 255.0f)
		blue = 255.0f;
	if (green > 255.0f)
		green = 255.0f;
	color.red = red;
	color.blue = blue;
	color.green = green;
	return (color);
}
