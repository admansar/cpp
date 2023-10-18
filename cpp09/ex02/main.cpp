#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac == 1)
		return (std::cerr << "Error\n", 1);
	if (ac == 2)
		return (std::cerr << "needs more then one element\n", 1);
	PmergeMe(ac, av);
}
