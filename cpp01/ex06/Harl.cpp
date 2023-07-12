#include <iostream>
#include "Harl.hpp"

Harl::Harl()
:colector(0)
{
	int i;
	
	i = 0;
	while (i < 4)
		to_compar[i++] = 0;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
	std::cout <<  "This is unacceptable ! I want to speak to the manager now.\n";
}

int Harl::get_colector(void)
{
	return (colector);
}

int calculating(std::string ss)
{
	int colector = 0;
	int i = -1;
	while (++i < (int)ss.size())
		colector += ss[i] * i;
	return (colector);
}


void Harl::complain(std::string level)
{
	int i;
	bool found;

	i = 0;
	found = 0;
	to_compar [0] = calculating("DEBUG");
	to_compar [1] = calculating("INFO");
	to_compar [2] = calculating("WARNING");
	to_compar [3] = calculating("ERROR");
	colector = calculating(level);
	while (i < 4)
	{
		if (to_compar[i] == colector)
			found = 1;
		i++;
	}
	if (!found)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return ;
	}
	switch (level[0])
	{
		case 'D': 
			std::cout << "[ DEBUG ]" << std::endl;
			Harl::debug();
			break;
		case 'I':
			std::cout << "[ INFO ]" << std::endl;
			Harl::info();
			break;
		case 'W':
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
			break;
		case 'E' : 
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			break;
	}
}
