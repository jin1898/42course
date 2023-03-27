SRCS = main.c image.c key.c map.c Text_editing_tools.c
OBJS := $(SRCS:.c=.o)
NAME := so_long

GNL_DIR = ./get_next_line
GNL_NAME = get_next_line.c get_next_line_utils.c
GNL = $(addprefix $(GNL_DIR)/,$(GNL_NAME))

INCLUDE := -I./get_next_line
CC = gcc

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(GNL)
	$(CC) -o $(NAME) $(OBJS) -Lmlx/ -lmlx -framework OpenGL -framework AppKit

%.o : %.c $(GNL_DIR)/%.c
	$(CC) -Wall -Wextra $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re
