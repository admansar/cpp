/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:08:29 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:16:12 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm ("robot", false, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	:AForm (name, false, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	:AForm (other.getName(), other.getSign(), other.getGts(), other.getGte())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->setSign(other.getSign());
	return (*this);
}

std::time_t my_rand()
{
	std::time_t current_time;
	std::time(&current_time);
	return current_time;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int random;

	if (!this->getSign())
		throw AForm::ShouldBeSigned();
	if (executor.getGrade() <= this->getGts())
		throw AForm::GradeTooLowException();
	random = my_rand() % 2;
	if (!(random == 0))
		std::cout << executor.getName() << " has been robotomized successfully 50%% of the time" << std::endl; 
	else
		std::cout << "the robotomy failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

