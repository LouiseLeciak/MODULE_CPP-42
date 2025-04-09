/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:34:53 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:18:14 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal";
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	(*this) = copy;
}


WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
	return;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal: Copy assignement operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}


///////////////
// functions //
///////////////

std::string	WrongAnimal::getType(void)
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "Glouk glouk" << std::endl;
}