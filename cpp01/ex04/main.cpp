#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	std::string line;
	std::string file;
	std::string s1;
	std::string s2;
	int h = 0;
	int k = 0;

	if (ac != 4)
		return (1);
	std::ifstream file_in;
	file_in.open(av[1]);
	if (!file_in.is_open())
	{
		std::cout << "something went wrong\n";
		return (1);
	}
	while (std::getline(file_in, line))
		file += line + '\n';
	k = file.find(av[2]);
	s1 = av[2];
	s2 = av[3];
	while (k + 1 && k <= (int)file.size())
	{
		h = file.size();
		file = file.substr(0, k) + s2 + file.substr (k + s1.size(), h);
		k = file.find(av[2], k + s1.size());
	}
	std::ofstream file_out;
	file_out.open(std::string(av[1]) + ".replace");
	if (file_out.is_open())
		file_out << file;
	else
	{
		std::cout << "something went wrong \n";
		return (1);
	}
	return (0);
}
