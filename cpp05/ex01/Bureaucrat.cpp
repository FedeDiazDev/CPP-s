/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:39:43 by fede              #+#    #+#             */
/*   Updated: 2024/09/17 17:31:09 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ): _name(""), _grade(150)
{
    std::cout << "Bureaucrat default constructor!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	    std::cout << "Bureaucrat " << this->_name << " constructor!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &b)
{
	*this = b;
}

Bureaucrat 	&Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
        this->_grade = b._grade;
	return (*this);
}

std::string Bureaucrat::getName( void ) const
{
    return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << "Bureaucrat " << this->_name << " destructor" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}


char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getGrade() < this->_grade)
		std::cout << this->_name << " could not sign " << form.getName() << " because its grade is too low." << std::endl;
	else
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	return;

}

std::ostream	&operator<<(std::ostream &str, Bureaucrat  &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
