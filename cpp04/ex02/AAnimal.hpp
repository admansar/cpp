/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:03 by admansar          #+#    #+#             */
/*   Updated: 2023/07/20 20:05:30 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal 
{
	protected :
		std::string type;
	public :
		AAnimal();
		AAnimal(AAnimal &other);
		AAnimal(std::string type);
		virtual void makeSound() const = 0;
		std::string getType() const;
		AAnimal &operator=(AAnimal const &other);
		virtual ~AAnimal();
};

#endif 
