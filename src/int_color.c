/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:48:50 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:51 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int				int_color(t_color color)
{
	unsigned int res;

	res = ((int)color.red << 16) + ((int)color.green << 8) + (int)(color.blue);
	return (res);
}
