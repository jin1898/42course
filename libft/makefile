SRCS = ft_itoa.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

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

.PHONY : all clean fclean re
