NAME = a.out

SRC = main.cpp AMateria.cpp Ice.cpp Character.cpp MateriaSource.cpp  Cure.cpp
FLAGS = -Wall -Wextra -Werror -std=c++17
INC = AMateria.hpp Ice.hpp Character.hpp MateriaSource.hpp  Cure.hpp
OBJ = $(SRC:.cpp=.o)
CC = c++

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp  $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
