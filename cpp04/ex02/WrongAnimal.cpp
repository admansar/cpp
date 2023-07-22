/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:15:20 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:30:03 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:type("")
{
	std::cout << "constructeur par default du class WrongAnimal\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "an animal sound ....\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
	:type (other.type)
{
	std::cout << "constructeur par copie du class WrongAnimal\n";
}

WrongAnimal WrongAnimal::operator=(WrongAnimal &other)
{
	type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "destructeur du class WrongAnimal\n";
}
