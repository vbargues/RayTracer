NAME = RT

FUNC = main init get_ambiant_light get_reflect new_vector \
int_color closest_inter key_events draw tool render normal_cone \
normal_plan normal_cylinder normal_sphere plan_inter sphere_inter \
cone_inter cylinder_inter prod_mat vec_dir get_rot_mat call_cone \
call_cylinder scalar_prod rot_point new_color get_image call_thread \
texture color_int texture_sphere normal_map texture_plan loading no_texture\
para_inter normal_para filter fdf display get_refract\
./parse/gnl/get_next_line ./parse/ft_llstadd ./parse/ft_llstnew ./parse/ft_lstadd ./parse/ft_lstnew ./parse/ft_stof ./parse/parse_brightness\
./parse/parse_camera ./parse/parse_color ./parse/parse_cone ./parse/parse_coord ./parse/parse_cylinder ./parse/parse_distance ./parse/parse_focal\
./parse/parse_height ./parse/parse_intensity ./parse/parse_light ./parse/parse_name ./parse/parse_object ./parse/parse_plan ./parse/parse_radius\
./parse/parse_render ./parse/parse_rotation ./parse/parse_scene ./parse/parse_sphere ./parse/create_sphere ./parse/create_cone ./parse/create_cylinder\
./parse/create_plan ./parse/malloc_ppchar ./parse/parse_texture ./parse/parse_normal_map ./parse/parse_object_rep ./parse/parse_fun_facts\
./parse/create_para ./parse/parse_para ./parse/parse_filter ./parse/parse_line\


SRC = $(addprefix src/, $(addsuffix .c, $(FUNC)))

OBJ = $(addprefix src/, $(addsuffix .o, $(FUNC)))

CC = clang

FLAGS = -Wall -Werror -Wextra -Ofast

NAME_TAR = transfer.tar

ILL = 'free'

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ src/libft/libft.a -lmlx -framework OpenGL -framework AppKit
	@sh ./sh_script/loading.sh RT
	@sh ./sh_script/name.sh

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

lib:
	@make -C src/libft/

clean:
	@rm -rf $(OBJ)
	@echo "\033[91;1mObject removed\033[0m";

lclean:
	@make -C src/libft/ clean

aclean: clean lclean

fclean: clean
	@rm -f $(NAME)
	@make -C src/libft/ clean
	@echo "\033[91;1mBinary removed\033[0m";

lfclean:
	@make -C src/libft/ fclean

afclean: fclean lfclean

re: fclean all

relib: lfclean lib

rea: relib re

rego: all
	@./RT 

tar: fclean
	@echo "\033[92;1mProject compressed\033[0m";
	@tar -cf $(NAME_TAR) $(SRC) Makefile $(addsuffix .h, $(NAME))

ill:
	cat $(SRC) | grep -n $(ILL)

norme:
	norminette $(SRC) rt.h

normelib:
	@make -C libft/ norme
