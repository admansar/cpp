#include "PhoneBook.h"

void decoration()
{
	std::cout << std::endl << "+-------------------------------------------+" << std::endl;
	std::cout <<         "|   index  |   name   | lastname | nickname |"; 
	std::cout << std::endl << "+-------------------------------------------+" << std::endl;
}

int  more_info(Contact *contact, int contact_index)
{
	std::string i;
	int re;

	std::cout << "for more details about this contact, print the index : ";
	std::cin >> i;
	re = atoi(i.c_str());
	if (re <= contact_index && re > 0)
		return (re);
	return (-1);
}

void print_just_ten(std::string str)
{
	int i;
	char ptr[12];

	strlcpy(ptr, str.c_str(), 11);
	ptr[11] = 0;
	i = 0;
	while (i < 9)
	{
		std::cout << ptr[i];
		i++;
	}
	if (ptr[9])
		std::cout << ".";
}

void gener_ws(int len)
{
	int i;

	i = (10 - len) / 2;
	while (i--)
		std::cout << ' ';
}

void print_it_cool(std::string c)
{
	int count;

	count =  c.length();
	if (count  < 10)
	{
		gener_ws(count);
		std::cout << c ;
		gener_ws(count-1);
		std::cout << "|" ;
	}
	else
	{
		print_just_ten(c);
		std::cout << "|" ;
	}
}
