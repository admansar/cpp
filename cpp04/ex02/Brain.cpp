/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:45:43 by admansar          #+#    #+#             */
/*   Updated: 2023/07/24 23:15:08 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "constructeur par default du Brain\n";
}

Brain::Brain(Brain const &other)
{
	int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
	std::cout << "constructeur par copie de Brain\n";
}

Brain &Brain::operator=(Brain const &other)
{
	int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "destructeur du Brain\n";
}


