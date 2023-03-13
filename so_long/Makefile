# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:37 by jsunwoo           #+#    #+#              #
#    Updated: 2023/03/10 16:08:37 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRCS	=	main.c

OBJS = $(SRCS:%.c=%.o)
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	# install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all