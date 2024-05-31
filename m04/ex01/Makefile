NAME = a.out

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
FLAGS = -Wall -Wextra -Werror #-std=c++17
INC = Animal.hpp Cat.hpp Brain.cpp
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
