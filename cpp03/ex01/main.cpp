/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:33 by admansar          #+#    #+#             */
/*   Updated: 2023/07/12 15:35:30 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Foo");
	ScavTrap b("Poo");


	a.attack("Poo");
	b.attack("Foo");
	a.beRepaired(2);
	b.beRepaired(5);
	a.beRepaired(20);
	b.takeDamage(10);
	a.takeDamage(31);
	b.takeDamage(4);
	a.takeDamage(1);
	b.guardGate();
	return (0);
}
