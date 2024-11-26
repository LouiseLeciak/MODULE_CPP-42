/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:18:32 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/31 08:23:35 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	return;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	(*this) = copy;
}


Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
	return;
}


Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal: Copy assignement operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}


///////////////
// functions //
///////////////

std::string	Animal::getType(void)
{
	return (this->_type);
}


void	Animal::makeSound(void)
{
	std::cout << "..." << std::endl;
}

