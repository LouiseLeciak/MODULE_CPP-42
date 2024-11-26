/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:07 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 14:08:05 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
	return;
}

Ice::Ice(const Ice& copy)
{
	this->_type = "ice";
	*this = copy;
}

const Ice& Ice::operator=(const Ice& copy)
{
	this->_type = copy._type;
	return (*this);
}

Ice::~Ice()
{
	return;	
}

//////////////////////////////

Ice* Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter& who)
{
	std::cout << "shoots an ice bolt at "
	<< who.getName() << " *" << std::endl;
}