/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:40:56 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/10/21 11:38:22 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
	: AForm(scf), _target(scf._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this != &assign)
	{
		this->AForm::operator=(assign);
		this->_target = assign._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() > this->getExecutionGrade())
			throw(GradeTooLowException());
		std::string filename = this->_target + "_shrubbery";
		std::ofstream outfile (filename.c_str());
		outfile << "          |>>> " << std::endl;
		outfile << "          |    " << std::endl;
		outfile << "      _  _|_  _    " << std::endl;
		outfile << "     |;|_|;|_|;|   " << std::endl;
		outfile << "     \\\\.    .  /   " << std::endl;
		outfile << "      \\\\:  .  /    " << std::endl;
		outfile << "       ||:   |     " << std::endl;
		outfile << "       ||:.  |     " << std::endl;
		outfile << "       ||:  .|     " << std::endl;
		outfile << "       ||:   |     " << std::endl;
		outfile << "       ||: , |     " << std::endl;
		outfile << "   __ ||:   | _    " << std::endl;
		outfile << "/____||_|  ||____\\" << std::endl;
		outfile << "      `--'`--'    " << std::endl;
		outfile.close();
	}
	else
	{
		throw(FormNotSigned());
	}
}