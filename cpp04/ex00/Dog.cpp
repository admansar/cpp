/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:47 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:22:38 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Dog::Dog()
	:Animal(), nom("")
{
	type = "Dog";
	std::cout << "constructeur par default du class dog\n";
}

Dog::Dog(Dog &other)
	:Animal(other), nom(other.nom)
{
	type = "Dog";
	std::cout << "constructeur par copie du class dog\n";
}

Dog::Dog(std::string name)
	:Animal(), nom(name)
{
	type = "Dog";
	std::cout << "constructeur par nom du class dog\n";
}

Dog &Dog::operator=(Dog const &other)
{
	type = other.type;
	nom = other.nom;
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "woaw\n";
}

std::string Dog::getname()
{
	return (nom);
}

Dog::~Dog()
{
	std::cout << "destructeur du class dog\n";
}

