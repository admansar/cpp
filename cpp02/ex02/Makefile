NAME = operators_game

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++ 

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address 

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
