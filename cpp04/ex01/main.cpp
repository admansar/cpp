/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:11 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 17:20:47 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int i;
	int midle;
	int how_many;

	i = 0;
	how_many = 2;
	const Animal *animal[how_many];

	midle = how_many / 2;
	while (i <  how_many)
	{
		if (i < midle)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		i++;
	}
	while (i--)
	{
		animal[i]->makeSound();
		delete animal[i];
	}

	//	const Animal* j = new Dog();
	//	const Animal* i = new Cat();
	//	delete j;
	//	delete i;
}
