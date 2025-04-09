/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 07:00:43 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 17:50:00 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

///////////////
//CONSTRUCTOR//
///////////////

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){};

Bureaucrat::Bureaucrat(const std::string name, int grade):
_name(name)
{
	//std::cout << "Bureaucrat: Constructor called\n" << std::endl;

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
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

void	Bureaucrat::signForm(AForm& form) const
{
	if (form.getSigned())
	{
		std::cout << form.getName() << " is already signed." << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because the lowest grade to sign is " << form.getSignGrade() << "." << std::endl;
	}

}


void	Bureaucrat::executeForm(AForm& form)
{
	try
	{
		form.execute(*this);
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
		<< " because " << e.what() << std::endl;
		return ;
	}
	
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
};



///////////////////////////////////


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};