# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 16:03:44 by jsunwoo           #+#    #+#              #
#    Updated: 2023/11/03 16:21:59 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
SCRS = test.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
FLAG = -Wall -Wextra -Werror -std=c++98
CC = g++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean


