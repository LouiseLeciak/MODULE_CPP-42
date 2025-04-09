/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:01:26 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 13:58:57 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	return;
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	(*this) = copy;
}


Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	return;
}


Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog: Copy assignement operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "Ouaf ouaf" << std::endl;
}