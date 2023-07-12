#include <iostream>


void to_upper(char **str)
{
	int i;
	
	i = -1;
	while ((*str)[++i])
		if (std::islower((*str)[i]))
			(*str)[i] -= 32;
}


void print_upper(char ***av)
{
	int i;

	i = -1;
	while ((*av)[++i])
	{
		to_upper(&(*av)[i]);
		std::cout << (*av)[i];
	}
	std::cout << "\n";
}


int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		av = av + 1;
		print_upper (&(av));
	}
	return 0;
}
