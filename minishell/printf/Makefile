CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99
NAME = libftprintf.a
SRCS = ft_printf.c ft_printer.c ft_print_hex.c
OBJ = $(SRCS:.c=.o)

SILENT = -s

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :
	make $(SILENT) fclean
	make $(SILENT) all

.PHONY: all clean fclean re

.SILENT: all clean fclean re $(NAME) $(OBJ)
