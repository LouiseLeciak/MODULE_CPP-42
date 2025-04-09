/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:25 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 17:48:34 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
# include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", 145, 137)
{
	//std::cout << "SCF: Constructor called." << std::endl;
	this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", 145, 137)
{
	//std::cout << "SCF: Constructor called." << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
AForm(copy)
{
	//std::cout << "SCF: Copy constructor called." << std::endl;
	this->_target = copy._target;
	(*this) = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "SCF: Destructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	(void)copy;
	return (*this);
}


void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_execGrade)
		throw Bureaucrat::GradeTooLowException();
	if (!this->_signed)
		throw AForm::isSignedException();

	std::ofstream	treeFile;
	std::string		treeFileName = this->_target + "_shrubbery";

	treeFile.open(treeFileName.c_str());
	treeFile << "      *" << std::endl;
	treeFile << "     ***" << std::endl;
	treeFile << "    *****" << std::endl;
	treeFile << "   *******" << std::endl;
	treeFile << "  *********" << std::endl;
	treeFile << " ***********" << std::endl;
	treeFile << "*************" << std::endl;
	treeFile << "     | |" << std::endl;
	treeFile << "     | |" << std::endl;
	treeFile.close();
}