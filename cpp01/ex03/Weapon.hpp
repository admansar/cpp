#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
	private : 
		std::string arme;
	public :
		Weapon();
		Weapon(std::string name);
		std::string getType();
		void setType(std::string arme);
};
#endif
