/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:03:45 by admansar          #+#    #+#             */
/*   Updated: 2023/07/14 21:03:47 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
class DiamondTrap : public FragTrap , public ScavTrap 
{
	private :
		std::string name;
	public :
		DiamondTrap();
		DiamondTrap(std::string lol);
		DiamondTrap(DiamondTrap &other);
		DiamondTrap &operator=(DiamondTrap &other);
		void attack(std::string l);
		void whoAmI();
		~DiamondTrap();
};

#endif
