#include "Zombie.hpp"

int main()
{
    Zombie* zombie = zombieHorde(5, "Foo");
	int i;

	i = -1;
    while (++i < 5) 
        zombie[i].announce();
    delete[] zombie;
    return (0);
}
