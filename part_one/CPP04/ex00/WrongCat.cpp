/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:42:09 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:00:38 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	return;
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	(*this) = copy;
}


WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
	return;
}


WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat: Copy assignement operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

void	WrongCat::makeSound(void)
{
	std::cout << "Croa croa" << std::endl;
}