#include "Weapon.hpp"

Weapon::Weapon()
: arme(""){}

Weapon::Weapon(std::string arme)
	:arme(arme){}

std::string Weapon::getType()
{
	return (this->arme);
}

void Weapon::setType(std::string arme)
{
	this->arme = arme;
}
