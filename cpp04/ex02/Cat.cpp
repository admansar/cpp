/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:21 by admansar          #+#    #+#             */
/*   Updated: 2023/07/20 20:03:17 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat()
	:AAnimal(), nom("")
{
	brain = new Brain();
	type = "Cat";
	std::cout << "constructeur par default du class cat\n";
}

Cat::Cat(Cat &other)
	:AAnimal(other) ,nom(other.nom) 
{
	brain = other.brain;
	type = "Cat";
	std::cout << "constructeur par copie du class cat\n";
}

Cat &Cat::operator=(Cat const &other)
{
	brain = other.brain;
	nom = other.nom;
	return (*this);
}

Cat::Cat(std::string name)
	:AAnimal (), nom(name)
{
	brain = new Brain();
	type = "cat";
	std::cout << "constructeur par nom du class cat\n";

}

void Cat::makeSound() const
{
	std::cout  << "miaw\n";
}

std::string Cat::getname()
{
	return (nom);
}

Cat::~Cat()
{
	std::cout << "destructeur par du class cat\n";
	delete brain;
}

