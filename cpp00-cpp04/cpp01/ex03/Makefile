NAME = ex03
SCRS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS = $(SCRS:.cpp=.o)
FLAG = -Wall -Wextra -Werror -std=c++98

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
	make clean
	make fclean

.PHONY: all clean fclean re
