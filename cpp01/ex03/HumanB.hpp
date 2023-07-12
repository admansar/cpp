#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>

class HumanB
{
	private :
		std::string name;
		Weapon *arme;
	public :
		HumanB();
		void setWeapon(Weapon &arme);
		HumanB(std::string name);
		void attack();
};

#endif
