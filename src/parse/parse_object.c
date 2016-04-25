/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:30:42 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:30:43 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char			**malloc_line(void)
{
	char			**line;

	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	return (line);
}

static void			init(t_obj *object)
{
	object->brightness = 0.0;
	object->spec = 0.0;
	object->transpa = 0.0;
	object->indice = 1.0;
	object->rep = 1;
	object->texture = NULL;
	object->normal_map = NULL;
	object->text_x = 1.0;
	object->text_y = 1.0;
	object->offset_x = 0.0;
	object->offset_y = 0.0;
}

static void			la_norme_a_pas_dit_bonjour(char **line, t_obj *object,
												int i, int fd)
{
	if ((*line)[i] && strncmp(*line + i, "brightness", 10) == 0)
		object->brightness = parse_brightness(fd);
	else if ((*line)[i] && strncmp(*line + i, "sphere", 6) == 0)
		create_sphere(object, fd);
	else if ((*line)[i] && strncmp(*line + i, "cylinder", 8) == 0)
		create_cylinder(object, fd);
	else if ((*line)[i] && strncmp(*line + i, "cone", 4) == 0)
		create_cone(object, fd);
	else if ((*line)[i] && strncmp(*line + i, "para", 4) == 0)
		create_para(object, fd);
	else if ((*line)[i] && strncmp(*line + i, "plan", 4) == 0)
		create_plan(object, fd);
	else if ((*line)[i] && strncmp(*line + i, "spec", 4) == 0)
		object->spec = parse_brightness(fd);
	else if ((*line)[i] && strncmp(*line + i, "transpa", 7) == 0)
		object->transpa = parse_brightness(fd);
	else if ((*line)[i] && strncmp(*line + i, "indice", 6) == 0)
		object->indice = parse_brightness(fd);
	else if ((*line)[i] && strncmp(*line + i, "texture", 7) == 0)
		object->texture = parse_texture(fd);
	else if ((*line)[i] && strncmp(*line + i, "normal", 6) == 0)
		object->normal_map = parse_normal_map(fd);
	else if ((*line)[i] && strncmp(*line + i, "rep", 3) == 0)
		object->rep = parse_object_rep(fd);
}

t_obj				*parse_object(int fd, int id)
{
	char			**line;
	int				i;
	t_obj			*object;

	object = (t_obj *)malloc(sizeof(t_obj));
	init(object);
	line = malloc_line();
	while (get_next_line(fd, line) > 0 && (*line)[0] != '}' && !(i = 0))
	{
		while ((*line)[i] && ((*line)[i] < 'a' || (*line)[i] > 'z'))
			i++;
		if ((*line)[i] && strncmp(*line + i, "color", 5) == 0)
			object->color = parse_color(fd);
		else if ((*line)[i] && strncmp(*line + i, "text_x", 6) == 0)
			object->text_x = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "text_y", 6) == 0)
			object->text_y = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "offset_x", 8) == 0)
			object->offset_x = parse_radius(fd);
		else if ((*line)[i] && strncmp(*line + i, "offset_y", 8) == 0)
			object->offset_y = parse_radius(fd);
		la_norme_a_pas_dit_bonjour(line, object, i, fd);
	}
	object->id = id;
	return (object);
}
