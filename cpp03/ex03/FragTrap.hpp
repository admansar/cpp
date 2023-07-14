/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:52:43 by admansar          #+#    #+#             */
/*   Updated: 2023/07/14 11:18:37 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


class FragTrap : virtual public ClapTrap
{
	public :
		FragTrap();	
		FragTrap(std::string name);
		FragTrap(FragTrap &other);
		void highFivesGuys(void);
		FragTrap &operator=(FragTrap &other);
		~FragTrap();
};

#endif
