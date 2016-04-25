/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:39:26 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:39:26 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_stof(char *str)
{
	float	ret;
	float	prout;
	int		i;
	int		neg;

	prout = 10.0;
	ret = 0;
	neg = 1;
	i = 0;
	while (str[i] == 9)
		i++;
	if (str[i] == '-' && i++)
		neg = -1;
	while (str[i] != '.')
		ret = ret * 10 + (str[i++] - 48);
	i++;
	while (str[i])
	{
		ret += (str[i++] - 48) / prout;
		prout *= 10;
	}
	return (ret * neg);
}
