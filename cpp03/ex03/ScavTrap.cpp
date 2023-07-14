/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:52:51 by admansar          #+#    #+#             */
/*   Updated: 2023/07/13 15:52:57 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->set_hit_point(100);
	this->set_energy_point(50);
	this->set_attack_damage(20);
	std::cout << "constructeur par defaut\n" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->get_energy_point() == 0)
	{
		std::cout << " no more energy point for " << this->get_name() << " sadly he cant move or do anything now :( !\n";
		this->set_life_stats(true);
	}
	else
		this->set_energy_point(this->get_energy_point() - 1);
	if (this->get_life_stats())
		return ;
	std::cout << "ScavTrap " << this->get_name()  << " attacks " << target << ", causing " << this->get_attack_damage() << " points of damage!\n";
}


ScavTrap::ScavTrap(ScavTrap &other)
{
	this->set_name(other.get_name());
	this->set_hit_point(other.get_hit_point());
	this->set_energy_point(other.get_energy_point());
	this->set_attack_damage(other.get_attack_damage());
	this->set_life_stats(other.get_life_stats());
}
void ScavTrap::guardGate()
{
	std::cout <<  this->get_name() << " GATE KEEPER MODE IS ENABLED 💂" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	this->set_name(other.get_name());
	this->set_hit_point(other.get_hit_point());
	this->set_energy_point(other.get_energy_point());
	this->set_attack_damage(other.get_attack_damage());
	this->set_life_stats(other.get_life_stats());
	return (*this);
}

ScavTrap::ScavTrap(std::string str)
{
	this->set_hit_point(100);
	this->set_energy_point(50);
	this->set_attack_damage(20);
	this->set_name(str);
	std::cout << "ScavTrap : " << this->get_name() << " is alive !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : " << this->get_name() << " died!" << std::endl;
}


