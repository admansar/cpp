#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	std::map<size_t, float> map;

	if (ac == 2)
		BitcoinExchange::btc (av[1], map);
	else
		std::cerr << "Error: could not open file.\n";
}
