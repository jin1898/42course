# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 17:32:56 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/10/27 18:21:46 by sunwoo-jin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SCRS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SCRS:.cpp=.o)
CC = g++
FLAG = -g -Wall -Wextra -Werror -std=g++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re