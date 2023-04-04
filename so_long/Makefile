# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 15:31:35 by jsunwoo           #+#    #+#              #
#    Updated: 2023/04/04 16:14:45 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c image.c key.c map.c text_editing_tools.c dfs.c get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:.c=.o)
GOBJS := $(GSRCS:.c=.o)
NAME := so_long

CC = cc

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	make clean -C ./mlx

re :
	make fclean
	make all

$(NAME) : $(GOBJS) $(OBJS)
	 make -C ./mlx 2>/dev/null
	$(CC) -o $(NAME) $(OBJS) -Lmlx/ -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) -Wall -Wextra -Werror -g3 $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re
