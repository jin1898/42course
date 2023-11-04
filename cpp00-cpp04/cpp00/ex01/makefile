# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 17:32:56 by sunwoo-jin        #+#    #+#              #
#    Updated: 2023/11/04 14:06:28 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SCRS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SCRS:.cpp=.o)
FLAG = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLAG) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
