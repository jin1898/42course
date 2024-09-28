# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 12:17:57 by jsunwoo           #+#    #+#              #
#    Updated: 2023/08/03 15:09:57 by jsunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror #-g #-fsanitize=thread #-fsanitize=address
SRCS = main.c util.c distroy.c init.c monitor.c one_philo.c eat.c
OBJ = $(SRCS:.c=.o)
SILENT = -s

all: $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "----Makefile all done ready to go----"
	@echo "How to run : \n ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] (optional:[number_of_times_each_philosopher_must_eat])"

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
