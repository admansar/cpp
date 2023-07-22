/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:54:55 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 15:55:09 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	: type("AMateria")
{}

AMateria::AMateria(AMateria const &other)
	:type (other.type)
{}

AMateria::AMateria(std::string const &type)
	:type(type)
{}

AMateria &AMateria::operator=(AMateria const &other)
{
	type = other.type;
	return (*this);
}


std::string const &AMateria::getType() const
{
	return (type);
}


void AMateria::use(ICharacter& target)
{
	std::cout << "i mean who need to use the " << target.getName() << std::endl;
}

AMateria::~AMateria()
{}


