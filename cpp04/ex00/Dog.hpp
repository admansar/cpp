/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:06:10 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:20:11 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
	private :
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

