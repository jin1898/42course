# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 15:31:35 by jsunwoo           #+#    #+#              #
#    Updated: 2023/03/31 07:42:16 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c image.c key.c map.c Text_editing_tools.c DFS.c get_next_line.c get_next_line_utils.c

OBJS := $(SRCS:.c=.o)
NAME := so_long

CC = gcc

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(GNLOBJS)
	$(CC) -o $(NAME) $(OBJS) -Lmlx/ -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) -Wall -Wextra -Werror -g3 $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re
