#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}


void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << ": No more BraiiiiiiinnnzzzZ..." << std::endl;
}

