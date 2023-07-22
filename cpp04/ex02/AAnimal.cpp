/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:39 by admansar          #+#    #+#             */
/*   Updated: 2023/07/20 20:05:06 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
	:type("")
{
	std::cout << "constructeur par default du class animal\n";
}

AAnimal::AAnimal(AAnimal &other)
	: type(other.type)
{
	std::cout << "constructeur par copie du class animal\n";
}

AAnimal::AAnimal(std::string type) 
{
	this->type = type;
	std::cout << "constructeur par nom du class animal \n";
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	type = other.type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (type);
}

AAnimal::~AAnimal()
{
	std::cout << "destructeur du class animal\n";
}

