/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:28:36 by admansar          #+#    #+#             */
/*   Updated: 2023/09/15 12:14:51 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm ("shrubbery", false, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm (name, false, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	: AForm (other)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	this->setSign(other.getSign());
	return (*this);
}

void the_tree(std::ofstream &fd)
{
	fd << "       ###\n";
	fd << "      #o###\n";
	fd << "    #####o###\n";
	fd << "   #o#\\#|#/###\n";
	fd << "    ###\\|/#o#\n";
	fd << "     # }|{  #\n";
	fd << "       }|{\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	std::ofstream 	file;

	if (!this->getSign())
		throw AForm::ShouldBeSigned();
	if (executor.getGrade() <= this->getGts())
		throw AForm::GradeTooLowException();
		std::cout << "TREE FILE IS ON CREAT MODE \n";
		file.open (std::string(executor.getName() + "_shrubbery"));
		if (file.is_open())
			the_tree(file);
		else
			std::cerr << "can't open file\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
