#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	int i;
	Zombie *z = new Zombie[n];

	i = -1;
	while (++i < n)
		z[i].set_name(name);
	return (z);
}
