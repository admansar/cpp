/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:23:20 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 00:23:21 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("Presedent", false, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string _name)
	:AForm(_name, false, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	:AForm(other)
{}

PresidentialPardonForm& PresidentialPardonForm::operator= (PresidentialPardonForm const &other)
{
	this->setSign(other.getSign());
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw AForm::ShouldBeSigned();
	if (executor.getGrade() <= this->getGts())
		throw AForm::GradeTooLowException();
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{}
