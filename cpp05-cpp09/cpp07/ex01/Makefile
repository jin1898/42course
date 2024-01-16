NAME = ex01
SCRS = ex01.cp
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
