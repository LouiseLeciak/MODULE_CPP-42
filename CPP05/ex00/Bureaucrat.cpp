/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 07:00:43 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/07 14:23:12 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

///////////////
//CONSTRUCTOR//
///////////////

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){};

Bureaucrat::Bureaucrat(const std::string name, int grade):
_name(name)
{
	//std::cout << "Bureaucrat: Constructor called\n" << std::endl;

	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->setGrade(grade);
}


Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	//std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	(*this) = copy;
}

////////////
//OPERATOR//
////////////

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	//std::cout << "Bureaucrat: Copy assignement operator called" << std::endl;
	
	this->_grade = copy.getGrade();
	
	return (*this);
}


std::ostream& operator<<(std::ostream& output, const Bureaucrat& bob)
{
	output << bob.getName() << " , bureaucrat grade " << bob.getGrade() << "." << std::endl;
	return (output);
}

//////////////
//DESTRUCTOR//
//////////////

Bureaucrat::~Bureaucrat()
{
	//std::cout << "\nBureaucrat: Destructor called" << std::endl;
	return;
}

//////////
//GETTER//
//////////

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}


int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//////////
//SETTER//
//////////

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

/////////////
//FUNCTIONS//
/////////////

void	Bureaucrat::incrementGrade()
{
	this->setGrade(this->_grade + 1);
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
		this->setGrade(this->_grade - 1);
	if (this->_grade > 150)
		throw GradeTooLowException();
}


///////////////////////////////////


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};