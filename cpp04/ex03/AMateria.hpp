/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:43:18 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 15:43:19 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		AMateria(std::string const & type);
		std::string const & getType() const; 
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};

#endif


