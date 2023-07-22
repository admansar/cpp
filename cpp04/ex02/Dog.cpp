/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:47 by admansar          #+#    #+#             */
/*   Updated: 2023/07/20 20:03:30 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Dog::Dog()
	:AAnimal(), nom("")
{
	brain = new Brain();
	type = "Dog";
	std::cout << "constructeur par default du class dog\n";
}

Dog::Dog(Dog &other)
	:AAnimal(other), nom(other.nom)
{
	brain = other.brain;
	type = "Dog";
	std::cout << "constructeur par copie du class dog\n";
}

Dog::Dog(std::string name)
	:AAnimal(), nom(name)
{
	brain = new Brain();
	type = "Dog";
	std::cout << "constructeur par nom du class dog\n";
}

Dog &Dog::operator=(Dog const &other)
{
	brain = other.brain;
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
	delete brain;
}

