#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>

class HumanA
{
	private :
		std::string name;
		Weapon &arme;
	public :
		HumanA(std::string name, Weapon &arme);
		void attack();
};
#endif
