/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:49:26 by vbargues          #+#    #+#             */
/*   Updated: 2015/12/05 16:49:27 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

t_vector		new_vector(t_point a, t_point b)
{
	t_vector ab;

	ab.origin = a;
	ab.dir = b;
	return (ab);
}
