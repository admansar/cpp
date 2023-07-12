/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:33 by admansar          #+#    #+#             */
/*   Updated: 2023/07/11 19:20:22 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Foo");
	ClapTrap b("Poo");


	a.attack("Poo");
	a.attack("Foo");
	a.beRepaired(2);
	b.beRepaired(5);
	a.beRepaired(20);
	b.takeDamage(10);
	a.takeDamage(31);
	b.takeDamage(4);
	a.takeDamage(1);
	return (0);
}
