#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(ScavTrap &other);
		ScavTrap(std::string str);
		ScavTrap &operator=(ScavTrap &other);
		void attack(const std::string &target);
		void guardGate();
		~ScavTrap();
};

#endif
