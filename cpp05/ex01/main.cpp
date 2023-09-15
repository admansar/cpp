/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:05:11 by admansar          #+#    #+#             */
/*   Updated: 2023/09/14 02:05:26 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	try
	{
		Bureaucrat	a("flan", 150);
		Form		b;


		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.signForm(b);
		a.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
