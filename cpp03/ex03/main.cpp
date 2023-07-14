/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:33 by admansar          #+#    #+#             */
/*   Updated: 2023/07/14 21:06:22 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"



int main()
{
	DiamondTrap test("ruined");

	test.whoAmI();
	test.attack("Foo");
	test.takeDamage(10);
	test.guardGate();
	test.highFivesGuys();
	test.beRepaired(20);
	return (0);
}

