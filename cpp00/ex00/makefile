# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 10:43:22 by jsunwoo           #+#    #+#              #
#    Updated: 2023/10/25 11:23:43 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SCRS = megaphone.cpp
OBJS = $(SCRS:.cpp=.o)
CC = g++
FLAG = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

