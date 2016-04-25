/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:50:53 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:50:54 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"
#include <math.h>

t_point		vec_dir(t_point a, t_point b)
{
	t_point		vec_ab;
	double		norme;

	vec_ab = new_point(b.x - a.x, b.y - a.y, b.z - a.z);
	norme = sqrt(pow(vec_ab.x, 2) + pow(vec_ab.y, 2) + pow(vec_ab.z, 2));
	vec_ab.x /= norme;
	vec_ab.y /= norme;
	vec_ab.z /= norme;
	return (vec_ab);
}
