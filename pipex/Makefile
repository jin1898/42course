# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 01:49:00 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/04/30 02:09:07 by sunwoo-jin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c make_pipe.c utils.c find_path.c free_everything.c
OBJS = $(SRCS:.c=.o)
NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GET_NEXT_LINE_OBJS)
	$(CC) -g3 $(CFLAGS) $(OBJS) $(GET_NEXT_LINE_OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(GET_NEXT_LINE_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
