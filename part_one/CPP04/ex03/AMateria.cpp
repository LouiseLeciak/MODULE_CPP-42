/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:12:28 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/31 08:28:12 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "Default";
	return;
}

AMateria::AMateria(const AMateria& copy)
{
	(*this) = copy;
}


AMateria::~AMateria()
{
	return;
}


AMateria& AMateria::operator=(const AMateria& copy)
{
	this->_type = copy._type;
	return (*this);
}


AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	return;
}

/////////////////////////////////////


std::string const & AMateria::getType() const
{
	return (this->_type);
}

AMateria* AMateria::clone() const
{
	return((AMateria *)this); // return this but cast it AMateria*
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* Materia used on "
	<< target.getName() << " *" << std::endl;
}