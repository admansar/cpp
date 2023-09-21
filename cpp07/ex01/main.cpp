#include <iostream>
#include "iter.hpp"

template <typename T>
void printer(T &elem)
{
	std::cout << elem << std::endl;
}

int main() 
{
	int			tab[] = {1, 2, 3};
	std::string strings[] = {"Hello", "World" , "!"};
	char 		chars[] = {'a', 'b', 'c'};

	size_t size = 3;

    iter(tab, size, printer<int>);
    iter(strings, size, printer<std::string>);
    iter(chars , size, printer<char>);

    return 0;
}

