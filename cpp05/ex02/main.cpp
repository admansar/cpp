/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:32:10 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 00:32:12 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	try
	{
		Bureaucrat				a("JaCk", 150);
		//	ShrubberyCreationForm	b;
		//  RobotomyRequestForm		b;
		PresidentialPardonForm		b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.signForm(b);
		b.execute(a);
		a.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
