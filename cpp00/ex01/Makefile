NAME = phonebook

SRC = ContacsClass.cpp PhonebookClass.cpp main.cpp utils.cpp

HEADER = Contact.hpp PhoneBook.h phonebook.hpp

OBJ = $(SRC:.cpp=.o)

CC = c++ 

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
