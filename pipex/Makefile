# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 01:49:00 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/05/02 15:37:56 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c make_pipe.c utils.c find_path.c free_everything.c
OBJS = $(SRCS:.c=.o)
NAME = pipex

BONUS_SRCS = main_bonus.c make_pipe_bonus.c utils_bonus.c find_path_bonus.c free_everything_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wextra -Werror -Wall -g
GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GET_NEXT_LINE_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GET_NEXT_LINE_OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(GET_NEXT_LINE_OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

bonus: $(BONUS_OBJS) $(GET_NEXT_LINE_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GET_NEXT_LINE_OBJS) -o $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
