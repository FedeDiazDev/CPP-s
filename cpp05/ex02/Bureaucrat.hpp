/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:28:40 by fede              #+#    #+#             */
/*   Updated: 2024/10/17 16:51:56 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat &b);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);
	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &form);
	void	executeForm(AForm const & form);
	Bureaucrat &operator=(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual char const *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual char const *what(void) const throw();
	};
};
std::ostream &operator<<(std::ostream& st, Bureaucrat &b);
#endif