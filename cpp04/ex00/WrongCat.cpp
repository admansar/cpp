/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:15:40 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:28:26 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "constructeur par default du class WrongCat\n";
}

WrongCat::WrongCat(WrongCat &other)
{
	type = other.type;
	std::cout << "constructeur par copie du class WrongCat\n";
}

WrongCat WrongCat::operator=(WrongCat &other)
{
	type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "maae ?\n";
}


WrongCat::~WrongCat()
{
	std::cout << "destructeur du class WrongCat\n";
}

