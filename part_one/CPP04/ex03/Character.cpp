/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:15:48 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 15:08:46 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "Default";
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
	return;
}

Character::Character(std::string const & name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
	return;
}

Character::Character(const Character& copy)
{
	//std::cout << "Character: Copy constructor called" << std::endl;
	
	(*this) = copy;
}

Character& Character::operator=(const Character& copy)
{
	this->_name = copy._name;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_items[i])
			delete this->_items[i];
		this->_items[i] = copy._items[i];
	}

	return (*this);
}

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
	for (int i = 3; i >= 0; i--)
	{
		if (this->_items[i])
		{
			delete this->_items[i];
			this->_items[i] = NULL;	
		}
	}
	return;
}


////////////////////////////////////////

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for(int i = 0; i < 4; i++)
	{
		if (!this->_items[i])
		{
			this->_items[i] = m;
			std::cout << this->_name << " have a new item "
			<< m->getType() << "." << std::endl;
			return;
		}
	}
	std::cout << "too much item." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || !this->_items[idx])
		return;
	
	std::cout << this->_name << " does not possess "
	<< this->_items[idx]->getType() << " anymore." << std::endl;

	this->_items[idx] = NULL;
	
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || !this->_items[idx])
		return;
		
	std::cout << "* " << this->_name << " ";
	
	this->_items[idx]->use(target); // here using the AMateria's use bcs using a materia
}