/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:06:10 by admansar          #+#    #+#             */
/*   Updated: 2023/07/20 20:01:12 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Dog.hpp"

class Dog : public AAnimal
{
	private :
		Brain *brain;
		std::string nom;
	public :
		Dog();
		Dog(Dog &other);
		Dog(std::string name);
		Dog &operator=(Dog const &other);
		void makeSound() const;
		std::string getname();
		~Dog();
};


#endif

