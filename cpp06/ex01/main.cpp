#include <iostream>
#include "Serializer.hpp"

typedef struct s_Data
{
	float	a;
	int		b;
	char	d;
	bool	e;
}				Data;

std::ostream& operator<< (std::ostream &os, Data data)
{
	os << "a = " << data.a << " b = " << data.b << " d = " << data.d << " e = " << data.e  << "\n";
	return (os);
}

int main ()
{
	Data a = {1.25f, 2, 'a', true};

	Data *b = Serializer::deserialize(Serializer::serialize(&a));

	std::cout << *b;
}
