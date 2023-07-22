/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:46:43 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 16:03:34 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(Cure const &other);
		Cure &operator=(Cure const &other);
		AMateria *clone () const ;
		void use(ICharacter& target);
		~Cure();
};

#endif 


