/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:15 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 12:34:18 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
	return;
}

Cure::Cure(const Cure& copy)
{
	this->_type = "cure";
	*this = copy;
}

const Cure& Cure::operator=(const Cure& copy)
{
	this->_type = copy._type;
	return (*this);
}

Cure::~Cure()
{
	return;	
}
///////////////////////////

Cure* Cure::clone() const
{
	Cure *newCure = new Cure(*this);
	return (newCure);
}

void Cure::use(ICharacter& who)
{
	std::cout << "heals "
	<< who.getName() << "'s wounds *" << std::endl;
}