/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:21:50 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 00:21:57 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _name);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm& operator= (PresidentialPardonForm const &other);

		void execute(Bureaucrat const & executor) const;

		~PresidentialPardonForm();
};

#endif
