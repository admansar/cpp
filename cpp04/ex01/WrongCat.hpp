/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:09:37 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 15:27:02 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(WrongCat &other);
		WrongCat operator=(WrongCat &other);
		std::string getType() const;
		void makeSound() const;
		~WrongCat();
};

#endif

