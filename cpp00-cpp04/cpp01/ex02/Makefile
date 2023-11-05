NAME = ex02
SCRSE = main.cpp
OBJS = $(SCRSE:.cpp=.o)
FLAG = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLAG) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
