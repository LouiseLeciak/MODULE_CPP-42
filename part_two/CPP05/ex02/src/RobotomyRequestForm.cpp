/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:21:28 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 17:49:22 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45)
{
	//std::cout << "RRF: Constructor called." << std::endl;
	this->_target = "Default";
	this->robotomy = true;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", 72, 45)
{
	//std::cout << "RRF: Constructor called." << std::endl;
	this->_target = target;
	this->robotomy = true;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
AForm(copy)
{
	//std::cout << "RRF: Copy constructor called." << std::endl;
	this->_target = copy._target;
	this->robotomy = true;
	(*this) = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RRF: Destructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	(void)copy;
	return (*this);
}


void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->_signed)
		throw AForm::isSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << "Brrrrrrrrrrr.." << std::endl;

	int i;
	i = std::rand() % 2;
	
	if (i == 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;

}