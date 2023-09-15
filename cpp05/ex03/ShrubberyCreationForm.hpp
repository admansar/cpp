/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:27:52 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:14:18 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm &other);
		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};


#endif


