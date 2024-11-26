/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:08:49 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:05:05 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "New ClapTrap created, it's name is " << _name << std::endl;
	std::cout << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "New ClapTrap created, it's name is " << name << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy." << std::endl;
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	this->_name = copy._name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy using =." << std::endl;
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	this->_name = copy._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl;
	std::cout << "ClapTrap destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is too tired to attack.." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << " causing " << this->_attackDamage << " points of damage !" << std::endl;
		this->_energyPoints--;
	}
	std::cout << "ClapTrap " << this->_name << " now has " << this->_energyPoints << " energy points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages !" << std::endl;
	if (amount > (unsigned int)this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " is not in good shape.. repairs needed"<< std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is too tired to repair.." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself and gets " << amount
				  << " hit points back." << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_energyPoints << " energy points." << std::endl;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " hit points." << std::endl;
}
