#include <iostream>
#include "Harl.hpp"

typedef struct details
{
	std::string level;
	void (Harl::*re)();
}				detail;

Harl::Harl()
:found(0)
{}

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

void Harl::complain(std::string  level)
{
	int i = 0;
	detail *niveau;

	niveau = new detail[4];
	niveau[0].level = "DEBUG";
	niveau[0].re = &Harl::debug;
	niveau[1].level = "INFO";
	niveau[1].re = &Harl::info;
	niveau[2].level = "WARNING";
	niveau[2].re = &Harl::warning;
	niveau[3].level = "ERROR";
	niveau[3].re = &Harl::error;
	while (i < 4)
	{
		if (niveau[i].level == level)
		{
			(this->*(niveau[i].re))();
			found = 1;
			break;
		}
			i++;
	}
	if (found == 0)
		std::cout << "INVALID\n";
	if (found == 1)
		found = 0;
	delete [] niveau;
}


