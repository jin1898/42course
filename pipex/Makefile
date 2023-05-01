# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 01:49:00 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/05/01 17:23:41 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main_bonus.c make_pipe_bonus.c utils_bonus.c find_path_bonus.c free_everything_bonus.c
OBJS = $(SRCS:.c=.o)
NAME = pipex

# BONUS_SRCS = main.c make_pipe.c utils.c find_path.c free_everything.c
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror  -g
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
