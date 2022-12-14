SRCS = ft_itoa.c ft_print_str.c ft_print_d_i.c ft_print_u.c ft_putchar_fd.c ft_print_percent.c ft_print_x.c ft_print_char.c ft_print_ptr.c ft_printf.c ft_strdup.c ft_strlen.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJS}
	ar -cr $@ ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBJS}
fclean : clean
	rm -rf ${NAME}
re : fclean all

.PHONY : clean fclean re
