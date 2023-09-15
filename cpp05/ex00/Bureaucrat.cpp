#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &os, Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

Bureaucrat::Bureaucrat()
	: name ("a random bureaucrat"), grade (150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name (name), grade (grade)
{
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name (other.name), grade (other.grade)
{}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
	other.grade = this->grade;
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increment(void)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void Bureaucrat::decrement(void)
{
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the grade is to high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the grade is to low");
}

Bureaucrat::~Bureaucrat()
{}
