/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:28:03 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:28:04 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
	try
	{
		{
			Intern someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
