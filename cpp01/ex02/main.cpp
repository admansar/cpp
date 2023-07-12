#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	std::cout << "L’adresse de la string en mémoire est : " << &var << std::endl;
	std::cout << "L’adresse stockée dans stringPTR est : " << stringPTR << std::endl;
	std::cout << "L’adresse stockée dans stringREF est : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "La valeur de la string est : " << var << std::endl;
	std::cout << "La valeur pointée par stringPTR est : " << *stringPTR << std::endl;
	std::cout << "La valeur pointée par stringREF est : " << stringREF << std::endl;
}
