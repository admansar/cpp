/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:05:13 by admansar          #+#    #+#             */
/*   Updated: 2023/09/14 02:05:26 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form ()
	: name("a random"), signed_at_constrution(false), grade_to_sign(150), grade_to_execute(150), reason ("not signed yet")
{
}

Form::Form (std::string name, bool sign, int gts, int gte)
	: name(name), signed_at_constrution(sign), grade_to_sign(gts), grade_to_execute(gte), reason ("not signed yet")
{}

Form::Form (const Form &other)	
	: name(other.name), signed_at_constrution(other.signed_at_constrution), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute), reason (other.reason)
{}

std::string Form::getName()
{
	return (name);
}

bool Form::getSign()
{
	return (signed_at_constrution);
}

int Form::getGts()
{
	return (grade_to_sign);
}

int Form::getGte()
{
	return (grade_to_execute);
}

std::string Form::getReason()
{
	return (reason);
}

void Form::setReason(std::string s)
{
	reason = s;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade to high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade to low");
}

Form& Form::operator=(const Form &other)
{
	this->signed_at_constrution = other.signed_at_constrution;
	return (*this);
}

std::ostream& operator<< (std::ostream &os, Form &f)
{
	os << f.getName() << " form, sign status : " << f.getSign() << " grade required to sign : " << f.getGts() << " grade required to execute : " << f.getGte();
	return os;
}

void Form::beSigned(Bureaucrat &b)
{
	try
	{
		if (b.getGrade() > 150)
			throw Form::GradeTooLowException();
		else if (b.getGrade() < 1)
			throw Form::GradeTooHighException();
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

Form::~Form()
{}


