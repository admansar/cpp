#include "Zombie.hpp"

Zombie::Zombie()
{
	name.clear();
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}


void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
  this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << ": No more BraiiiiiiinnnzzzZ..." << std::endl;
}

