# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 01:49:00 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/05/04 20:47:56 by jsunwoo          ###   ########.fr        #
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

ifdef WITH_BONUS
	OBJ_SWITCH = $(BONUS_OBJS)
else
	OBJ_SWITCH = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_SWITCH) $(GET_NEXT_LINE_OBJS)
	make -C ./get_next_line
	$(CC) $(CFLAGS) $(OBJ_SWITCH) $(GET_NEXT_LINE_OBJS) -o $(NAME) -L./get_next_line -lgnl

clean:
	rm -f $(OBJS) $(GET_NEXT_LINE_OBJS)
	rm -f $(BONUS_OBJS)
	make clean -C ./get_next_line

fclean: clean
	rm -f $(NAME)
	make fclean -C ./get_next_line

bonus:
	@make WITH_BONUS=1 $(NAME)


re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
