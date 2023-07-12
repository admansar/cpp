NAME = account

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

OBJ = Account.o tests.o

all : $(NAME)


$(NAME) : $(OBJ) Account.hpp
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean re all fclean
