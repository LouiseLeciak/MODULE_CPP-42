/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:59:21 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:16:08 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	return;
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	(*this) = copy;
}


Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
	return;
}


Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat: Copy assignement operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "Miaou miaou" << std::endl;
}