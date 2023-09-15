/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:05:19 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:12:33 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string	name;
		bool				signed_at_constrution;
		const int			grade_to_sign;
		const int			grade_to_execute;
		std::string			reason;
	public :
		AForm();
		AForm (std::string name, bool sign, int gts, int gte);
		AForm (const AForm &other);
		AForm& operator=(const AForm &other);

		std::string	getName()const;
		bool		getSign()const;
		void		setSign(bool in);
		int			getGts()const;
		int			getGte()const;
		std::string	getReason()const;
		void		setReason(std::string s);

		void	beSigned(Bureaucrat const &b);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class	GradeTooHighException;
		class	GradeTooLowException;
		class	ShouldBeSigned;

		virtual ~AForm();
};

class AForm::GradeTooHighException: public std::exception
{
	public :
		const char *what() const throw();
};

class AForm::GradeTooLowException: public std::exception
{
	public :
		const char *what() const throw();
};

class AForm::ShouldBeSigned: public std::exception
{
	public :
		const char *what() const throw();
};

std::ostream& operator<<(std::ostream &os, AForm &f);

#endif


