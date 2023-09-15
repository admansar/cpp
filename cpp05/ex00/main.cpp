/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:05:57 by admansar          #+#    #+#             */
/*   Updated: 2023/09/14 02:05:58 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat a("flan", 150);

		std::cout << a << std::endl;
		a.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
