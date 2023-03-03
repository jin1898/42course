# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 11:06:15 by jsunwoo           #+#    #+#              #
#    Updated: 2023/03/03 11:44:49 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#push_swap.c argument_factory.c argument_factory2.c doubly_linked_list.c ft_split.c indexing.c op2.c sand.c
NAME := push_swap

SRC = push_swap.c argument_factory.c argument_factory2.c doubly_linked_list.c ft_split.c indexing.c op2.c sand.c
OBJ = $(SRC:.c=.o)

LIBFT := libft.a
LIB_NAME := ft
LIB_SRCS := push_swap.c argument_factory.c argument_factory2.c doubly_linked_list.c ft_split.c indexing.c op2.c sand.c
LIB_OBJS := $(LIB_SRCS:.c=.o)

AR := ar
ARFLAGS := -rc
CC := gcc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(LIBFT) $(NAME)
re : fclean all


$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^
$(LIBFT) : $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?
%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean