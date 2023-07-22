/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:55:40 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 16:03:49 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure")
{}

Cure::Cure(Cure const &other)
	:AMateria(other)
{}

Cure &Cure::operator=(Cure const &other)
{
	type = other.type;
	return (*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure()
{}

