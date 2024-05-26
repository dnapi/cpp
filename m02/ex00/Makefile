NAME = harlFilter

SRC = main.cpp Fixed.cpp

FLAGS = -Wall -Wextra -Werror
INC = Fixed.hpp
OBJ = $(SRC:.cpp=.o)
CC = c++

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
