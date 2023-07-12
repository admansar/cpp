#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arme)
:name(name), arme (arme) {}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << arme.getType() << std::endl;
}
