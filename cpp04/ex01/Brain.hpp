/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:43:38 by admansar          #+#    #+#             */
/*   Updated: 2023/07/19 16:46:18 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		~Brain();
};

#endif
