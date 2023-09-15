/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:05:19 by admansar          #+#    #+#             */
/*   Updated: 2023/09/14 02:05:26 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string	name;
		bool				signed_at_constrution;
		const int			grade_to_sign;
		const int			grade_to_execute;
		std::string			reason;
	public :
		Form();
		Form (std::string name, bool sign, int gts, int gte);
		Form (const Form &other);
		Form& operator=(const Form &other);

		std::string	getName();
		bool		getSign();
		int			getGts();
		int			getGte();
		std::string	getReason();
		void		setReason(std::string s);
		
		void	beSigned(Bureaucrat &b);

		class	GradeTooHighException;
		class	GradeTooLowException;

		~Form();
};

class Form::GradeTooHighException: public std::exception
{
	public :
		const char *what() const throw();
};

class Form::GradeTooLowException: public std::exception
{
	public :
		const char *what() const throw();
};

std::ostream& operator<<(std::ostream &os, Form &f);

#endif


