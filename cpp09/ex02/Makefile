NAME = PmergeMe 

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
