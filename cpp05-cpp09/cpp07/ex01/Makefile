NAME = ex01
SCRS = main.cpp
OBJS = $(SCRS:.cpp=.o)
FLAG = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLAG) -c -o $@ $<

clean:
	rm -rf $(OBJS)
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf *.dSYM
re:
	make fclean
	make all

.PHONY: all clean fclean re
