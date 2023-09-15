/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:05:13 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:13:15 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm ()
	: name("a random"), signed_at_constrution(false), grade_to_sign(150), grade_to_execute(150), reason ("not signed yet")
{
}

AForm::AForm (std::string name, bool sign, int gts, int gte)
	: name(name), signed_at_constrution(sign), grade_to_sign(gts), grade_to_execute(gte), reason ("not signed yet")
{}

AForm::AForm (const AForm &other)	
	: name(other.name), signed_at_constrution(other.signed_at_constrution), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute), reason (other.reason)
{}

std::string AForm::getName() const
{
	return (name);
}

bool AForm::getSign() const
{
	return (signed_at_constrution);
}

void AForm::setSign(bool in)
{
	signed_at_constrution = in;
}

int AForm::getGts() const
{
	return (grade_to_sign);
}

int AForm::getGte() const
{
	return (grade_to_execute);
}

std::string AForm::getReason() const
{
	return (reason);
}

void AForm::setReason(std::string s)
{
	reason = s;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade to high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade to low");
}

const char *AForm::ShouldBeSigned::what() const throw()
{
	return ("should sign in !!");
}

AForm& AForm::operator=(const AForm &other)
{
	this->signed_at_constrution = other.signed_at_constrution;
	return (*this);
}

std::ostream& operator<< (std::ostream &os, AForm &f)
{
	os << f.getName() << " form, sign status : " << f.getSign() << " grade required to sign : " << f.getGts() << " grade required to execute : " << f.getGte();
	return os;
}

void AForm::beSigned(Bureaucrat const &b)
{
	try
	{
		if (b.getGrade() > 150)
			throw AForm::GradeTooLowException();
		else if (b.getGrade() < 1)
			throw AForm::GradeTooHighException();
		if (b.getGrade() >= this->grade_to_sign)
			this->signed_at_constrution = true;
		else
			this->signed_at_constrution = false;
	}
	catch (std::exception &e)
	{
		reason = std::string (e.what());
	}
}	

AForm::~AForm()
{}
