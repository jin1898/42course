NAME = ex00
SCRS = main.cpp ClapTrap.cpp
OBJS = $(SCRS:.cpp=.o)
CXXFLAG = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONEY: all clean fclean re
