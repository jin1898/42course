# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:58:34 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/27 14:03:49 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
BONUS			=	cub3D_bonus
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror


SRCS			=	srcs/main.c									\
					srcs/init/init_cub3d.c						\
					srcs/init/init_cub3d_parse.c				\
					srcs/init/line_validation.c					\
					srcs/init/line_validation_map.c				\
					srcs/init/line_validation_rgb.c				\
					srcs/init/line_validation_rgb_to_int.c		\
					srcs/init/line_validation_texture.c			\
					srcs/init/load_images.c						\
					srcs/init/load_images_texture.c				\
					srcs/init/map_validation.c					\
					srcs/init/map_validation_dfs.c				\
					srcs/init/map_validation_is_surround.c		\
					srcs/init/reset_terminal_interface.c		\
					srcs/hook/key_press.c						\
					srcs/hook/key_release.c						\
					srcs/hook/mouse_move.c						\
					srcs/hook/mouse_press.c						\
					srcs/hook/mouse_release.c					\
					srcs/hook/loop_hook.c						\
					srcs/hook/reset_vector.c					\
					srcs/hook/title_menu_key_press.c			\
					srcs/hook/title_menu_loop_hook.c			\
					srcs/hook/title_menu_mouse_move.c			\
					srcs/hook/title_menu_mouse_press.c			\
					srcs/render/render_mini_map.c				\
					srcs/render/render_game_scene.c				\
					srcs/render/render_game_scene_line.c		\
					srcs/render/render_game_scene_line_wall.c	\
					srcs/render/render_cross_hair.c				\
					srcs/render/render_shoot.c					\
					srcs/render/render_hand.c					\
					srcs/render/render_ammo_count.c				\
					srcs/utils/exit_game.c						\
					srcs/utils/free_split.c						\
					srcs/utils/free_game.c						\
					srcs/utils/destroy_instance.c				\
					srcs/utils_draw/draw_line_to_img.c			\
					srcs/utils_draw/draw_pixel_to_img.c			\
					srcs/utils_draw/draw_rect_to_img.c			\
					srcs/utils_draw/pipette_color_from_img.c	\
					srcs/utils_draw/set_pixel.c					\
					srcs/utils_draw/rgb8_to_int.c				\
					srcs/utils_math/add_vector.c				\
					srcs/utils_math/deg_to_rad.c				\
					srcs/utils_math/rotate_vector.c				\
					srcs/utils_math/substract_vector.c			\
					srcs/utils_math/set_vector.c				\
					srcs/utils_math/move_vector.c				\
					srcs/utils_math/distance_vector.c			\
					srcs/utils_math/map_int.c					\
					srcs/utils_math/map_double.c				\
					srcs/utils_ray_casting/ray_casting.c		\
					srcs/utils_ray_casting/init_ray_casting.c	\


SRCS_BONUS = 		srcs/bonus/main_bonus.c									\
					srcs/bonus/init/init_cub3d_bonus.c						\
					srcs/bonus/init/init_cub3d_parse_bonus.c				\
					srcs/bonus/init/line_validation_bonus.c					\
					srcs/bonus/init/line_validation_map_bonus.c				\
					srcs/bonus/init/line_validation_rgb_bonus.c				\
					srcs/bonus/init/line_validation_rgb_to_int_bonus.c		\
					srcs/bonus/init/line_validation_texture_bonus.c			\
					srcs/bonus/init/load_images_bonus.c						\
					srcs/bonus/init/load_images_texture_bonus.c				\
					srcs/bonus/init/map_validation_bonus.c					\
					srcs/bonus/init/map_validation_dfs_bonus.c				\
					srcs/bonus/init/map_validation_is_surround_bonus.c		\
					srcs/bonus/init/reset_terminal_interface_bonus.c		\
					srcs/bonus/hook/key_press_bonus.c						\
					srcs/bonus/hook/key_release_bonus.c						\
					srcs/bonus/hook/mouse_move_bonus.c						\
					srcs/bonus/hook/mouse_press_bonus.c						\
					srcs/bonus/hook/mouse_release_bonus.c					\
					srcs/bonus/hook/loop_hook_bonus.c						\
					srcs/bonus/hook/reset_vector_bonus.c					\
					srcs/bonus/hook/title_menu_key_press_bonus.c			\
					srcs/bonus/hook/title_menu_loop_hook_bonus.c			\
					srcs/bonus/hook/title_menu_mouse_move_bonus.c			\
					srcs/bonus/hook/title_menu_mouse_press_bonus.c			\
					srcs/bonus/render/render_mini_map_bonus.c				\
					srcs/bonus/render/render_game_scene_bonus.c				\
					srcs/bonus/render/render_game_scene_line_bonus.c		\
					srcs/bonus/render/render_game_scene_line_wall_bonus.c	\
					srcs/bonus/render/render_cross_hair_bonus.c				\
					srcs/bonus/render/render_shoot_bonus.c					\
					srcs/bonus/render/render_hand_bonus.c					\
					srcs/bonus/render/render_ammo_count_bonus.c				\
					srcs/bonus/utils/exit_game_bonus.c						\
					srcs/bonus/utils/free_split_bonus.c						\
					srcs/bonus/utils/free_game_bonus.c						\
					srcs/bonus/utils/destroy_instance_bonus.c				\
					srcs/bonus/utils_draw/draw_line_to_img_bonus.c			\
					srcs/bonus/utils_draw/draw_pixel_to_img_bonus.c			\
					srcs/bonus/utils_draw/draw_rect_to_img_bonus.c			\
					srcs/bonus/utils_draw/pipette_color_from_img_bonus.c	\
					srcs/bonus/utils_draw/set_pixel_bonus.c					\
					srcs/bonus/utils_draw/rgb8_to_int_bonus.c				\
					srcs/bonus/utils_math/add_vector_bonus.c				\
					srcs/bonus/utils_math/deg_to_rad_bonus.c				\
					srcs/bonus/utils_math/rotate_vector_bonus.c				\
					srcs/bonus/utils_math/substract_vector_bonus.c			\
					srcs/bonus/utils_math/set_vector_bonus.c				\
					srcs/bonus/utils_math/move_vector_bonus.c				\
					srcs/bonus/utils_math/distance_vector_bonus.c			\
					srcs/bonus/utils_math/map_int_bonus.c					\
					srcs/bonus/utils_math/map_double_bonus.c				\
					srcs/bonus/utils_ray_casting/ray_casting_bonus.c		\
					srcs/bonus/utils_ray_casting/init_ray_casting_bonus.c	\



OBJS			=	$(SRCS:.c=.o)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)
HEADER			=	-I ./includes/cub3d.h -I ./includes/cub3d_bonus.h
LIBFT_A			=	srcs/libft/libft.a
LIBMLX_FLAGS	=	-L. -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS) ./includes/cub3d.h
	$(MAKE) -C srcs/libft
	make -j 1 -C srcs/mlx 2>/dev/null
	cp ./srcs/mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) $(LIBFT_A) $(LIBMLX_FLAGS) -o $(NAME)
	@clear
	@echo "\n\033[1;33m"
	@echo ' _   _______ _      _      ___________  ______ '
	@echo '| | / /_   _| |    | |    |  ___| ___ \ | ___ \'
	@echo '| |/ /  | | | |    | |    | |__ | |_/ / | |_/ /'
	@echo '|    \  | | | |    | |    |  __||    /  | ___ \'
	@echo '| |\  \_| |_| |____| |____| |___| |\ \  | |_/ /'
	@echo '\_| \_/\___/\_____/\_____/\____/\_| \_| \____/ '
	@echo "Mandatory part                    Killer banana\n\n"
	@echo '                 GAME IS READY                 '
	@echo "\n"
	@echo "          run [./cub3D *.cub] to play          "
	@echo ''
	@echo "\033[0m\n"

$(BONUS) : $(OBJS_BONUS) ./includes/cub3d_bonus.h
	$(MAKE) -C srcs/libft
	make -j 1 -C srcs/mlx 2>/dev/null
	cp ./srcs/mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAGS) $(HEADER) $(OBJS_BONUS) $(LIBFT_A) $(LIBMLX_FLAGS) -o $(BONUS)
	@clear
	@echo "\n\033[1;33m"
	@echo ' _   _______ _      _      ___________  ______ '
	@echo '| | / /_   _| |    | |    |  ___| ___ \ | ___ \'
	@echo '| |/ /  | | | |    | |    | |__ | |_/ / | |_/ /'
	@echo '|    \  | | | |    | |    |  __||    /  | ___ \'
	@echo '| |\  \_| |_| |____| |____| |___| |\ \  | |_/ /'
	@echo '\_| \_/\___/\_____/\_____/\____/\_| \_| \____/ '
	@echo "Bonus part                        Killer banana\n\n"
	@echo '                 GAME IS READY                 '
	@echo "\n"
	@echo "          run [./cub3D *.cub] to play          "
	@echo ''
	@echo "\033[0m\n"

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean :
	$(MAKE) -C srcs/libft clean
	$(MAKE) -C srcs/mlx clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean :
	$(MAKE) -C srcs/libft fclean
	$(MAKE) -C srcs/mlx clean
	rm -rf $(OBJS) $(OBJS_BONUS) $(NAME) $(BONUS) ./libmlx.dylib

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all re clean fclean bonus

