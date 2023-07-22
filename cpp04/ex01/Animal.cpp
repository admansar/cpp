/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:39 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:18:53 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	:type("")
{
	std::cout << "constructeur par default du class animal\n";
}

Animal::Animal(Animal &other)
	: type(other.type)
{
	std::cout << "constructeur par copie du class animal\n";
}

Animal::Animal(std::string type) 
{
	this->type = type;
	std::cout << "constructeur par nom du class animal \n";
}

Animal &Animal::operator=(Animal const &other)
{
	type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout  << "making a sound\n";
}

Animal::~Animal()
{
	std::cout << "destructeur du class animal\n";
}

