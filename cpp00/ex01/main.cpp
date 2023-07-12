#include "PhoneBook.h"

int main()
{
	std::string str;
	PhoneBook book;

	book.init_PhoneBook();
	std::cout << "\033[0;32m";
	std::cout << "###############>welcome to contacts<###############\n" << std::endl;
	while (1)
	{
		std::cout << "\033[0;32m\t     -->to add contact print ADD<--\033[0;36m \n" << std::endl;
		std::cout << "\t    -->to do a search print SEARCH<--\n" << std::endl;
		std::cout << "\033[0;31m\t        -->to exit print exit<--\n" << std::endl;
		std::cout << "\033[0;37moption : ";
		std::cin >> str;
		if (std::cin.eof())
			break ;
		if (str.c_str())
		{
			if (!strcmp("ADD", str.c_str()))
				book.add_contact();
			else if (!strcmp("SEARCH", str.c_str()))
				book.ls();
			else if (!strcmp("EXIT", str.c_str()))
				break;
		}
	}
}
