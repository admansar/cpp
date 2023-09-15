/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:08:24 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 00:13:18 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
};

#endif
