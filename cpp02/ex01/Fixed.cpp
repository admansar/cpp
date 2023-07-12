/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:16:48 by admansar          #+#    #+#             */
/*   Updated: 2023/07/08 22:16:49 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(int i)
	:nombre_en_virgule_fix(roundf(i * pow(2, 8)))
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float f)
	:nombre_en_virgule_fix(roundf(f * pow(2, 8)))
{
	std::cout << "Float constructor called\n";
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed::Fixed()
: nombre_en_virgule_fix(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->nombre_en_virgule_fix = other.nombre_en_virgule_fix;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	this->nombre_en_virgule_fix = other.nombre_en_virgule_fix;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::toInt() const
{
	return ((int)nombre_en_virgule_fix / pow(2, 8));
}

float Fixed::toFloat() const
{
	return ((float)nombre_en_virgule_fix / pow(2, 8));
}


