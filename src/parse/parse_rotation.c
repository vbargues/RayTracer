/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:31:23 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:31:24 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_rotation		parse_rotation(int fd)
{
	t_rotation	rotation;
	char		**line;
	float		ret;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	get_next_line(fd, line);
	ret = ft_stof(*line);
	rotation.x = ret;
	get_next_line(fd, line);
	ret = ft_stof(*line);
	rotation.y = ret;
	get_next_line(fd, line);
	ret = ft_stof(*line);
	rotation.z = ret;
	rotation.m16 = get_rot_mat(rotation.x, rotation.y, rotation.z);
	rotation.negm16 = get_rot_mat(-rotation.x, -rotation.y, -rotation.z);
	return (rotation);
}
