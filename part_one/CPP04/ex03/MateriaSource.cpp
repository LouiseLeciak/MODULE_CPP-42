/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:52:05 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 13:57:45 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	*this = copy;
}

const MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete this->_source[i];
		this->_source[i] = copy._source[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
		{
			delete this->_source[i];
			this->_source[i] = NULL;
		}
	}
}

////////////////////////////

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_source[i] == NULL)
		{
			this->_source[i] = materia;
			return ;
		}
	}
	
	std::cout << "You cannot learn more Materia." << std::endl;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for(int i = 0; i < 4; i++)
		if(this->_source[i] && this->_source[i]->getType() == type)
			return (this->_source[i]->clone());

	std::cout << "Unknown type, materia not created." << std::endl;
	return (NULL);
}
