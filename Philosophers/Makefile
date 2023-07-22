# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 12:17:57 by jsunwoo           #+#    #+#              #
#    Updated: 2023/07/19 21:03:38 by sunwoo-jin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address #-fsanitize=thread
SRCS = main.c util.c distroy.c init.c monitor.c
OBJ = $(SRCS:.c=.o)
SILENT = -s

all: $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "----Makefile all done ready to go----"
%.o : %.c
	@printf "\033[Kcompile $(notdir $<)\r"
	cc $(CFLAGS) -c $^ -o $@
clean :
	rm -f $(OBJ)
	@echo "----Makefile clean done----"
fclean : clean
	rm -f $(NAME)
	@echo "----Makefile fclean done----"

re :
	make $(SILENT) fclean
	make $(SILENT) all

.PHONY: all clean fclean re c.o
.SILENT : all clean fclean re $(OBJ) $(NAME)
