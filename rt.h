/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <lsalomme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:48:03 by lsalomme          #+#    #+#             */
/*   Updated: 2015/12/05 16:55:01 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define KEYPRESS 2
# define KEYRELEASE 3
# define MAX_DEPTH 5
# define NB_THREAD 4
# include <pthread.h>

enum				e_filter
{
	NONE,
	SEPIA,
	BLACK_WHITE,
	RED,
	BLUE,
	GREEN,
	NEG,
	TEST
};

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_vector
{
	t_point			origin;
	t_point			dir;
}					t_vector;

typedef struct		s_rotation
{
	float			x;
	float			y;
	float			z;
	float			*m16;
	float			*negm16;
}					t_rotation;

typedef struct		s_sphere
{
	t_point			center;
	float			radius;
}					t_sphere;

typedef struct		s_cylinder
{
	t_point			center;
	t_point			top;
	t_point			bot;
	t_rotation		rot;
	float			radius;
	float			height;
}					t_cylinder;

typedef struct		s_cone
{
	t_point			center;
	t_point			dir;
	t_rotation		rot;
	float			angle;
	float			top;
	float			bot;
}					t_cone;

typedef struct		s_para
{
	t_point			center;
	float			a;
	float			b;
	t_rotation		rot;
}					t_para;

typedef struct		s_plan
{
	float			a;
	float			b;
	float			c;
	float			d;
	t_point			def;
}					t_plan;

typedef struct		s_light
{
	t_sphere		body;
	t_color			color;
	float			intensity;
}					t_light;

typedef struct		s_img
{
	void			*img;
	int				width;
	int				height;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;
	char			*name;
}					t_img;

typedef struct		s_obj
{
	t_point			(*normal)(struct s_obj, t_point, t_vector);
	t_color			(*texturing)(struct s_obj, t_point, t_vector);
	int				(*fonc)(struct s_obj, t_vector, double *);
	void			*obj;
	t_color			color;
	float			brightness;
	float			spec;
	float			transpa;
	float			id;
	float			indice;
	t_img			*texture;
	t_img			*normal_map;
	int				rep;
	float			text_x;
	float			text_y;
	float			offset_x;
	float			offset_y;
}					t_obj;

typedef struct		s_lst
{
	t_obj			*obj;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_llst
{
	t_light			*light;
	struct s_llst	*next;
}					t_llst;

typedef struct		s_screen
{
	int				height;
	int				width;
	int				dist;
	t_point			top_left;
	t_point			top_right;
	t_point			bot_left;
	t_point			bot_right;
}					t_screen;

typedef struct		s_cam
{
	t_point			pos;
	t_rotation		rot;
	float			focale;
	t_screen		screen;
}					t_cam;

typedef struct		s_scene
{
	t_lst			*lst_obj;
	t_llst			*lst_light;
	t_cam			camera;
	int				depth;
	float			refl;
	t_point			normal;
	t_point			ray;
	float			scal;
	t_color			color;
}					t_scene;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_img			img;
	int				**tab;
	int				line_ind;
	int				line_thread;
	pthread_t		*threads;
	t_scene			scene;
	int				escape_pressed;
	char			*name;
	char			*calc_line;
	char			**fun_facts;
	enum e_filter	filter;
	char			fdf;
}					t_win;

void				texture(t_win *win);
void				params_init(t_win *win, char *file);
int					key_press(int keycode, t_win *win);
int					key_release(int keycode, t_win *win);
int					key_hook(t_win *win);
int					expose_hook(t_win *win);
void				adapt_pixel_in_image(t_win *win, int color, int x, int y);
t_point				new_point(float x, float y, float z);
t_point				rot_point(t_point point, float *m16);
int					call_sphere(t_obj obj, t_vector ray, double *dist);
int					call_plan(t_obj obj, t_vector ray, double *dist);
int					call_cylinder(t_obj obj, t_vector ray, double *dist);
int					call_cone(t_obj obj, t_vector ray, double *dist);
int					call_para(t_obj obj, t_vector ray, double *dist);
t_point				call_normal_sphere(t_obj obj, t_point inter, t_vector ray);
t_point				call_normal_plan(t_obj obj, t_point inter, t_vector ray);
t_point				call_normal_para(t_obj obj, t_point inter, t_vector ray);
t_point				call_normal_cylinder(t_obj obj, t_point inter,
										t_vector ray);
t_point				call_normal_cone(t_obj obj, t_point inter, t_vector ray);
t_point				vec_dir(t_point a, t_point b);
double				scalar_prod(t_point u, t_point v);
int					cone_inter(t_cone cone, t_vector ray, double *dist);
int					cylinder_inter(t_cylinder cyl, t_vector ray, double *dist);
float				*prod_mat(float *m1, float *m2);
float				*get_rot_mat(float a, float b, float c);
t_color				new_color(float red, float blue, float green);
t_vector			new_vector(t_point a, t_point b);
int					int_color(t_color color);
t_color				color_int(int color);
double				find_closest_inter(t_lst *ptr_lst, t_obj *obj_ptr,
										double *dist, t_vector ray);
t_color				get_ambiant_light(t_scene scene, t_vector ray,
									t_obj object, t_point inter);
t_color				get_reflect(t_scene scene, t_vector ray,
							t_obj object, t_point inter);
void				get_image(t_win *win);
t_color				get_first_ray(t_scene scene, t_vector ray, t_obj object,
							t_point inter);
void				params_init(t_win *win, char *file);
void				call_thread(t_win *win);
void				*call_render(void *wiin);
void				normal_map(t_win *win);
t_point				normal_sphere(t_sphere sph, t_point inter, t_vector ray);
t_color				texture_sphere(t_obj object, t_point normal, t_vector ray);
t_color				texture_plan(t_obj object, t_point inter, t_vector ray);
t_color				no_texture(t_obj object, t_point inter, t_vector ray);
char				**parse_fun_facts(void);
void				calc_line(t_win *win);
int					filter(t_color c, t_win *win);
void				map_fdf(t_win *win);
t_color				get_refract(t_scene scene, t_vector ray, t_obj object,
									t_point inter);
int					display(t_win *win);

#endif
