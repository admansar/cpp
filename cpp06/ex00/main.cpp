/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 08:55:04 by admansar          #+#    #+#             */
/*   Updated: 2023/09/18 08:56:44 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		try 
		{
			ScalarConverter::convert (av[1]);
		}
		catch (const char *e)
		{
			std::cout << e << std::endl;
		}
	}
	else
		std::cout << "wrong number of args\nplease give me a number after " + std::string(av[0]).erase(0, 2) << std::endl;
}
