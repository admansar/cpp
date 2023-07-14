/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:06:26 by admansar          #+#    #+#             */
/*   Updated: 2023/07/14 21:06:28 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string sname)
:ClapTrap(sname + "_clap_name"), FragTrap(sname), ScavTrap(sname)
{
	std::cout << "Cool day to call the DiamondTrap constrat" << std::endl;
	this->set_hit_point(FragTrap::get_hit_point());
	this->set_energy_point(ScavTrap::get_energy_point());
	this->set_attack_damage(FragTrap::get_attack_damage());
	this->set_life_stats(true);
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
:ClapTrap(other.name + "_clap_name"), FragTrap(other.name), ScavTrap(other.name)
{
	name = other.name;
	this->set_hit_point(other.get_hit_point());
	this->set_energy_point(other.get_energy_point());
	this->set_attack_damage(other.get_attack_damage());
	this->set_life_stats(other.get_life_stats());
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	name = other.get_name();
	ClapTrap::set_name(name + "_clap_name");
	this->set_hit_point(other.get_hit_point());
	this->set_energy_point(other.get_energy_point());
	this->set_attack_damage(other.get_attack_damage());
	this->set_life_stats(other.get_life_stats());
	return (*this);
}

void DiamondTrap::attack(std::string who)
{
	ScavTrap::attack(who);
}

void DiamondTrap::whoAmI()
{
	std::cout << "a lot of parent .... im DiamondTrap , my name is " << name << " one of my parents name is " << ClapTrap::get_name() << " he is a ClapTrap btw" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Ohh no im dying ... the destrcut is calling me ..... " << std::endl;
}
