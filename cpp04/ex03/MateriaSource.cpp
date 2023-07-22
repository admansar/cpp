/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:02:16 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 16:06:51 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
	:index(0), name("")
{
	int i;

	i = 0;
	while (i < 4)
	{
		materia[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(std::string name)
	:index(0), name(name)
{
	int i;

	i = 0;
	while (i < 4)
	{
		materia[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(MateriaSource const &other)
	:index(0), name(other.name)
{
	int i;

	i = 0;
	while (i < 4)
	{
		materia[i] = other.materia[i];
		i++;
	}
}

AMateria  *MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	return (0);
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	int i;

	i = 0;
	index = other.index;
	name = other.name;
	while (i < 4)
	{
		delete materia[i];
		materia[i] = other.materia[i];
		i++;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (index < 4)
	{
		materia[index] = m->clone();
		delete m;
		index++;
	}
	else
	{
		std::cout << "sorry , but the max is 4 materia\n";
	}
}

MateriaSource::~MateriaSource()
{
	int i;

	i = 0;
	while (i < index)
		delete materia[i++];
}


