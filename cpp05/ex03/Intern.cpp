/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:26:52 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:28:36 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern& Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	int			i;
	int			j;
	AForm		*re[3];
	std::string form[3];

	form[0] = "robotomy request";
	form[1] = "shrubbery creation";
	form[2] = "presidential pardon";
	re[0] = new RobotomyRequestForm(target);
	re[1] = new ShrubberyCreationForm(target);
	re[2] = new PresidentialPardonForm(target);
	i = 0;
	while (i < 3)
	{
		if (name == form[i])
		{
			j = -1;
			while (++j < 3)
				if (j != i)
					delete re[j];
			std::cout << "Intern creates " << form[i] << "\n";
			return re[i];
		}
		i++;
	}
	j = -1;
	while (++j < 3)
		delete re[j];
	std::cerr << "can not creat " << name << std::endl;
	return (NULL);
}

Intern::~Intern()
{}
