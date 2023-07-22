/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:59:31 by admansar          #+#    #+#             */
/*   Updated: 2023/07/22 15:59:33 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria	*materia[4];
		int			index;
		std::string	name;
	public :
		MateriaSource();
		MateriaSource(std::string name);
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
		~MateriaSource();
};
#endif


