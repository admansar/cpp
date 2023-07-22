/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:45:26 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 15:45:41 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		AMateria *clone () const ;
		void use(ICharacter& target);
		~Ice();
};

#endif


