# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 17:32:56 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/10/28 16:22:24 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SCRS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SCRS:.cpp=.o)
CC = g++
FLAG = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
