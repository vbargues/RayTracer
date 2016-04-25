/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_prod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:41 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:52:14 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

double			scalar_prod(t_point u, t_point v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
