/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:17:29 by admansar          #+#    #+#             */
/*   Updated: 2023/07/08 22:17:34 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
:nbr_virgule_fixe(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &to_cpy)
{
	std::cout << "Copy constructor called\n";
	this->setRawBits(to_cpy.getRawBits());
}

Fixed& Fixed::operator=( Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(other.getRawBits());
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	nbr_virgule_fixe = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (nbr_virgule_fixe);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n"; 
}
