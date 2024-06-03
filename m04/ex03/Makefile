NAME = a.out

SRC = main.cpp AMateria.cpp Ice.cpp #Character.cpp #Cure.cpp
FLAGS = -Wall -Wextra -Werror -std=c++17
INC = AMateria.hpp
#INC = $(SRC:.cpp=.hpp)
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
