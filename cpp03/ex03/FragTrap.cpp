/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:52:48 by admansar          #+#    #+#             */
/*   Updated: 2023/07/13 15:52:57 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->set_hit_point(100);
	this->set_energy_point(100);
	this->set_attack_damage(30);
	std::cout << "anonymos FragTrap is here" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->set_hit_point(100);
	this->set_energy_point(100);
	this->set_attack_damage(30);
	this->set_name(name);
	std::cout << "FragTrap : " << this->get_name() << " is alive !" << std::endl;
}

FragTrap::FragTrap(FragTrap &other)
{
	this->set_name(other.get_name());
	this->set_hit_point(other.get_hit_point());
	this->set_energy_point(other.get_energy_point());
	this->set_attack_damage(other.get_attack_damage());
	this->set_life_stats(other.get_life_stats());
	std::cout << "FragTrap copy : " << this->get_name() << " is alive !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	this->set_name(other.get_name());
	this->set_hit_point(other.get_hit_point());
	this->set_energy_point(other.get_energy_point());
	this->set_attack_damage(other.get_attack_damage());
	this->set_life_stats(other.get_life_stats());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : " << this->get_name() << " died!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << this->get_name() << " needs a high five !!" << std::endl;
}


