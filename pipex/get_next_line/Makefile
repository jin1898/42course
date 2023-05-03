SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = libgnl.a
CC = cc
CFLAGS = -Wextra -Werror -Wall -g

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)
