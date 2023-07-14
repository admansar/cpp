/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:54:21 by admansar          #+#    #+#             */
/*   Updated: 2023/07/13 15:54:31 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name("anonyme"), hit_point(10), energy_point(10), attack_damage(0), died(false)
{
	std::cout << "be carefull from " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "constructeur par copie\n";
	this->name = other.name;
	this->hit_point = other.hit_point;
	this->energy_point = other.energy_point;
	this->attack_damage = other.attack_damage;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	this->name = other.name;
	this->hit_point = other.hit_point;
	this->energy_point = other.energy_point;
	this->attack_damage = other.attack_damage;
	died = other.died;
	return (*this);
}

ClapTrap::ClapTrap(std::string prenom)
	:name(prenom), hit_point(10), energy_point(10), attack_damage(0), died(false)
{
	std::cout << name << " is breathing!!" << std::endl;
}


std::string ClapTrap::get_name()
{
	return (name);
}

unsigned int ClapTrap::get_hit_point()
{
	return (hit_point);
}

unsigned int ClapTrap::get_energy_point()
{
	return (energy_point);
}

unsigned int ClapTrap::get_attack_damage()
{
	return (attack_damage);
}

bool ClapTrap::get_life_stats()
{
	return (died);
}


void ClapTrap::set_hit_point(unsigned int in)
{
	hit_point = in;
}

void ClapTrap::set_energy_point(unsigned int in)
{
	energy_point = in;
}

void ClapTrap::set_attack_damage(unsigned int in)
{
	attack_damage = in;
}

void ClapTrap::set_life_stats(bool in)
{
	died = in;
}

void ClapTrap::set_name(std::string name)
{
	this->name = name;
}



void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < hit_point)
	{
		hit_point -= amount;
		std::cout << name << " took damage , he still have " << hit_point << " hit point for the moment\n";
	}
	else
	{
		hit_point = 0;
		std::cout << name << " no more hit point for " << name << " sadly he cant move or do anything now !\n";
		died = true;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (died)
		return ;
	hit_point += amount;
	std::cout << name << " healed !!, he have " << hit_point << " hit point for the moment\n";
	if (energy_point == 0)
	{
		std::cout << " no more energy point for " << name << " sadly he cant move or do anything now !\n";
		died = true ;
		return ;
	}
	energy_point--;
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_point == 0)
	{
		std::cout << " no more energy point for " << name << " sadly he cant move or do anything now !\n";
		died = true ;
	}
	else
		energy_point--;
	if (died)
		return ;
	std::cout << "ClapTrap " << name  << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
}


ClapTrap::~ClapTrap()
{
	std::cout << "c'est le destructeur par default\n";
}


