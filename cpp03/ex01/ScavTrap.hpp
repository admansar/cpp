/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:53:57 by admansar          #+#    #+#             */
/*   Updated: 2023/07/13 15:54:08 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(ScavTrap &other);
		ScavTrap(std::string str);
		ScavTrap &operator=(ScavTrap &other);
		void attack(const std::string &target);
		void guardGate();
		~ScavTrap();
};

#endif
