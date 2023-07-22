/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:55:40 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 15:56:07 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
Ice::Ice()
	:AMateria("ice")
{}

Ice::Ice(Ice const &other)
	:AMateria(other)
{}

Ice &Ice::operator=(Ice const &other)
{
	type = other.type;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice()
{}
