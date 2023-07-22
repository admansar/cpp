/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:01:27 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 16:01:28 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
	:name(name), index(0)
{
	int i;

	i = 0;
	while (i < 4)
	{
		inventaire[i] = NULL;
		i++;
	}
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	if (index < 4 && !inventaire[index])
	{
		inventaire[index] = m->clone();
		delete m;
		if (index < 4)
			index++;
	}
	else
	{
		std::cout << "pas d'emplacement vide pour cette inventaire : " << m << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 4)
	{
		if (idx > index)
		{
			std::cout << "you cant unequip something you didnt equip !!\n";
		}
		else
		{
			delete inventaire[idx];
			inventaire[idx] = NULL;
		}
	}
	else
	{
		std::cout << "really ??, how can i unequip in a plcae that you dont have unloocked yet!!\n";
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4)
	{
		if (idx <= index)
		{
			if (inventaire[idx]->getType() == "ice" || inventaire[idx] ->getType() == "cure")
				inventaire[idx]->use(target);
			else
				std::cout << "type is not defined\n";
		}
		else
			std::cout << "no inventaire is in there !!\n";
	}
	else
	{
		std::cout << "really ??, you really know that you didnt unlock more space for more then 4 inventaire\n";
	}
}

Character::~Character()
{
	int i;

	i = 0;
	while (i < index)
		delete inventaire[i++];
}


