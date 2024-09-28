NAME = ex03
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp Character.cpp IMateriaSource.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
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
	make fclean
	make all

.PHONY: all clean fclean re
