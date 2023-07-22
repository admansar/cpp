/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:03 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:18:57 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal 
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(Animal &other);
		Animal(std::string type);
		virtual void makeSound() const;
		std::string getType() const;
		Animal &operator=(Animal const &other);
		virtual ~Animal();
};

#endif 
