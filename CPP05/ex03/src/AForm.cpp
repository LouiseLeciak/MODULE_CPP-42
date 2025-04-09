/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:20:58 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 17:46:46 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

///////////////
//CONSTRUCTOR//
///////////////

AForm::AForm(): _name("Default"), _signed("false"), _signGrade(150), _execGrade(150){};

AForm::AForm(const std::string name, int signGrade, int execGrade):
_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	//std::cout << "AForm: Constructor called\n" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}


AForm::AForm(const AForm& copy):
_name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	//std::cout << "AForm: Copy constructor called" << std::endl;
	(*this) = copy;
}

////////////
//OPERATOR//
////////////

AForm& AForm::operator=(const AForm& copy)
{
	//std::cout << "AForm: Copy assignement operator called" << std::endl;
	this->_signed = copy._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName();
	if (form.getSigned())
		os << ", a signed form by a rank " << form.getSignGrade() << " or greater.";
	else
		os << ", an unsigned form. Rank needed to sign: " << form.getSignGrade() << " or greater.";
	os << " Rank needed to execute: " << form.getExecGrade();
	return (os);
}

//////////////
//DESTRUCTOR//
//////////////

AForm::~AForm()
{
	//std::cout << "\nForm: Destructor called" << std::endl;
	return;
}

//////////
//GETTER//
//////////

std::string	AForm::getName() const
{
	return (this->_name);
}


int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}


////////////
//FUNCTION//
////////////

void	AForm::beSigned(const Bureaucrat& tester)
{
	if (tester.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

//////////////////////////////////////

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
};

const char *AForm::isSignedException::what(void) const throw()
{
	return ("The form is not signed.");
};