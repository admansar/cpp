#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB()
{
	name.clear();
}

void HumanB::setWeapon(Weapon &arme)
{
	this->arme = &arme;
}

HumanB::HumanB(std::string name)
:name(name){}

void HumanB::attack()
{
	if (arme)
	std::cout << name << " attacks with their " << arme->getType() << std::endl;
}


