/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:04:27 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 16:48:21 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
		std::string nom;
	public :
		Cat();
		Cat(Cat &other);
		Cat(std::string name);
		std::string  getname();
		Cat &operator=(Cat const &other);
		void makeSound() const;
		~Cat();
};

#endif
