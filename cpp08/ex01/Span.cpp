/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:51:03 by admansar          #+#    #+#             */
/*   Updated: 2023/09/22 20:51:04 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::LessThenTwo : public std::exception
{
	public :
		const char *what() const throw();
};

const char *Span::LessThenTwo::what() const throw()
{
	return ("there is less then two numbers stored in !!");
}

class Span::FullSpan : public std::exception
{
	public :
		const char *what() const throw();
};


const char *Span::FullSpan::what() const throw()
{
	return ("Span : Full Span");
}

Span::Span()
	:n (0)
{
	v.reserve(0);
}

Span::Span(const Span &other)
	:v (other.v), n (other.n)
{}

Span::Span(const unsigned int n)
	:n (n)
{
	v.reserve(n);
}

Span& Span::operator=(const Span &other)
{
	this->v = other.v;
	this->n = other.n;
	return (*this);
}

void Span::addNumber(unsigned int num_to_add)
{
	if (v.size() == v.capacity())
		throw Span::FullSpan();
	v.push_back(num_to_add);
}


unsigned int Span::sorting_helper(std::string type)
{
	std::vector<int> sorted;
	unsigned int i;

	sorted.reserve(n - 1);
	i = -1;
	while (++i < v.size())
		sorted.push_back(abs(v[i + 1] - v[i]));
	std::sort (sorted.begin(), sorted.end());
	if (type == "short")
		return (sorted[0]);
	else
		return (sorted[sorted.size() - 1]);
}


unsigned int Span::shortestSpan()
{
	if (this->n < 2)
		throw LessThenTwo();
	return (this->sorting_helper("short"));
}

unsigned int Span::longestSpan()
{
	if (this->n < 2)
		throw LessThenTwo();
	return (this->sorting_helper("long"));
}

Span::~Span ()
{}

void Span::addNumbers(iter begin, iter end)
{
	iter it = begin;
    while  (it != end)
	{
        addNumber(*it);
		it++;
    }
}