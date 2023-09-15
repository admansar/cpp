/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:43:39 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 10:10:11 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
typedef AForm Form;

class Bureaucrat
{
	private :
		const std::string	name;
		int					grade;
	public : 
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat&	operator=(Bureaucrat &other);

		const	std::string getName() const;
		int		getGrade() const;
		void	increment();
		void 	decrement();
		void	signForm(Form const &f);
		void	executeForm(Form const & form);

		class GradeTooHighException;
		class GradeTooLowException;

		~Bureaucrat();
};


class Bureaucrat::GradeTooHighException : public std::exception
{
	public :
		const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public :
		const char *what() const throw();
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &b);

#endif


