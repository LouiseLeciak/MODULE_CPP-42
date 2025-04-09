/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:20:58 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/13 14:22:23 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

///////////////
//CONSTRUCTOR//
///////////////

Form::Form(): _name("Default"), _signed("false"), _signGrade(150), _execGrade(150){};

Form::Form(const std::string name, int signGrade, int execGrade):
_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	//std::cout << "Form: Constructor called\n" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}


Form::Form(const Form& copy):
_name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	//std::cout << "Form: Copy constructor called" << std::endl;
	(*this) = copy;
}

////////////
//OPERATOR//
////////////

Form& Form::operator=(const Form& copy)
{
	//std::cout << "Form: Copy assignement operator called" << std::endl;
	this->_signed = copy._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
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

Form::~Form()
{
	//std::cout << "\nForm: Destructor called" << std::endl;
	return;
}

//////////
//GETTER//
//////////

std::string	Form::getName() const
{
	return (this->_name);
}


int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

bool Form::getSigned() const
{
	return (this->_signed);
}


////////////
//FUNCTION//
////////////

void	Form::beSigned(const Bureaucrat& tester)
{
	if (tester.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

//////////////////////////////////////

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};