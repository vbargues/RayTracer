/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:39:52 by lsalomme          #+#    #+#             */
/*   Updated: 2016/02/13 12:39:53 by lsalomme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "gnl/get_next_line.h"
# include "../../rt.h"
# include "obj_list.h"

float			ft_stof(char *str);
t_color			parse_color(int fd);
t_point			parse_coord(int fd);
t_vector		parse_vector();
t_rotation		parse_rotation(int fd);
float			parse_brightness(int fd);
float			parse_distance(int fd);
float			parse_focal(int fd);
float			parse_radius(int fd);
float			parse_height(int fd);
float			parse_intensity(int fd);
char			*parse_name(int fd);
enum e_filter	parse_filter(int fd);
t_win			parse_render(t_win win, int fd);
t_cam			parse_camera(int fd);
t_obj			*parse_object(int fd, int id);
int				parse_object_rep(int fd);

void			create_sphere(t_obj *object, int fd);
void			create_cone(t_obj *object, int fd);
void			create_cylinder(t_obj *object, int fd);
void			create_plan(t_obj *object, int fd);
void			create_para(t_obj *object, int fd);

t_cylinder		*parse_cylinder(int fd);
t_cone			*parse_cone(int fd);
t_sphere		*parse_sphere(int fd);
t_plan			*parse_plan(int fd);
t_para			*parse_para(int fd);
t_light			*parse_light(int fd);

void			parse_scene(int fd, t_win *win);
void			parse_line(t_win *win, char **line, int i, int fd);
char			**malloc_ppchar();
t_img			*parse_texture(int fd);
t_img			*parse_normal_map(int fd);

#endif
