/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:06:25 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 17:48:48 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5)
{
	//std::cout << "PPF: Constructor called." << std::endl;
	this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", 25, 5)
{
	//std::cout << "PPF: Constructor called." << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
AForm(copy)
{
	//std::cout << "PPF: Copy constructor called." << std::endl;
	this->_target = copy._target;
	(*this) = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PPF: Destructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	(void)copy;
	return (*this);
}


void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_execGrade)
		throw Bureaucrat::GradeTooLowException();
	if (!this->_signed)
		throw AForm::isSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}