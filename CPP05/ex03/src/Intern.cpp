/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:09:37 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/22 16:51:20 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	//std::cout << "Intern: Default constructor called" << std::endl;
	_allForms[0].fonction = &Intern::createShrubbery;
	_allForms[0].form = "shrubbery creation";

	_allForms[1].fonction = &Intern::createRobotomy;
	_allForms[1].form = "robotomy request";

	_allForms[2].fonction = &Intern::createPresident;
	_allForms[2].form = "presidential pardon";
	
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

const Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}


Intern::~Intern()
{
	//std::cout << "Intern: Destructor called" << std::endl;
}


/////////////
//FUNCTIONS//
/////////////


AForm*	Intern::createShrubbery(const std::string target)
{
	std::cout << "Intern creates a Shrubbery form." << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(const std::string target)
{
	std::cout << "Intern creates a Robotomy form." << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresident(const std::string target)
{
	std::cout << "Intern creates a Presidential form." << std::endl;
	return (new PresidentialPardonForm(target));
}

Intern::fptr	Intern::whatForm(std::string name)
{
	for (int i = 0; i < 3; i++)
	{
		if(_allForms[i].form == name)
			return _allForms[i].fonction;
	}
	std::cout << "The form: " + name + " does not exist." << std::endl;
	return (NULL);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	fptr	find = whatForm(name);
	if (!find)
		return (NULL);
	return (this->*find)(target);
}
