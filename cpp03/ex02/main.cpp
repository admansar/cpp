/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:33 by admansar          #+#    #+#             */
/*   Updated: 2023/07/13 15:52:12 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Foo");
	ScavTrap b("Poo");
	FragTrap c("Goo");


	a.attack("Poo");
	b.attack("Foo");
	c.attack("Poo");
	c.attack("Foo");
	a.beRepaired(2);
	b.beRepaired(5);
	c.beRepaired(9);
	a.beRepaired(20);
	b.takeDamage(10);
	c.takeDamage(70);
	a.takeDamage(31);
	b.takeDamage(4);
	b.takeDamage(20);
	a.takeDamage(1);
	c.takeDamage(10);
	b.guardGate();
	c.highFivesGuys();
	return (0);
}
