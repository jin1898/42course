# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 15:25:59 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/10/27 17:43:09 by sunwoo-jin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Megaphone
SCRS = megaphone.cpp
OBJS = $(SCRS:.cpp=.o)
CC = g++
FLAG = -Wall -Wextra -Werror -std=g++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re