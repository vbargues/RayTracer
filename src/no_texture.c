/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:31:39 by tjouin            #+#    #+#             */
/*   Updated: 2016/02/11 17:32:30 by tjouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_color	no_texture(t_obj object, t_point inter, t_vector ray)
{
	(void)ray;
	(void)inter;
	return (object.color);
}
