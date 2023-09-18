/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:34:03 by admansar          #+#    #+#             */
/*   Updated: 2023/09/18 17:41:40 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

class Base
{
	public :
		virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base::~Base()
{};

int rand_gen()
{
	std::srand(time(NULL));
	return (std::rand());
}

Base * generate(void)
{
	Base	*re;
	int		i;

	i = rand_gen() % 3;
	if (!i)
		re = new A;
	else if (!(i - 1))
		re = new B;
	else
		re = new C;
	return (re);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "the type is : A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "the type is : B\n";
	else if (dynamic_cast<C*>(p))	
		std::cout << "the type is : C\n";
	else
		std::cerr << "error\n";
}

void identify(Base& p)
{
	try
	{
		if (&(dynamic_cast<A&>(p)))
			std::cout << "the type is : A\n";
	}
	catch (...)
	{
		try
		{
			if (&dynamic_cast<B&>(p))
				std::cout << "the type is : B\n";
		}
		catch (...)
		{
			try 
			{
				if (&dynamic_cast<C&>(p))	
					std::cout << "the type is : C\n";
			}
			catch (...)
			{
				std::cerr << "error\n";
			}
		}
	}
}

int main ()
{
	Base *base;

	base = generate();
	identify(base);
	identify(*base);

	delete base;
}
