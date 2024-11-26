/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:38:37 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 07:55:18 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_gateKeeperMode = false;
	std::cout << "\033[0;31mScavTrap created. It's name is \033[0m" << this->_name << std::endl;
	std::cout<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_gateKeeperMode = false;
	std::cout << "\033[0;31mScavTrap created. It's  name is \033[0m" << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "\033[0;31mCopy ScavTrap\033[0m" << std::endl;
	this->_gateKeeperMode = copy._gateKeeperMode;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "\033[0;31mCopy ScavTrap using =\033[0m" << std::endl;
	this->_gateKeeperMode = copy._gateKeeperMode;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl;
	std::cout << "\033[0;31mScavTrap destroyed.\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		std::cout << "\033[0;31mScavTrap " << this->_name << " is too tired to attack..\033[0m" << std::endl;
	else
	{
		std::cout << "\033[0;31mScavTrap " << this->_name << " attacks " << target
				  << " causing " << this->_attackDamage << " points of damage !\033[0m" << std::endl;
		this->_energyPoints--;
	}
	std::cout << "\033[0;31mScavTrap " << this->_name << " now has " << this->_energyPoints
	<< " energy points.\033[0m" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_gateKeeperMode == true)
		std::cout << "\033[0;31mScavTrap " + _name << " already is in Gate keeper mode.\033[0m"
		<< std::endl;
	else
	{
		this->_gateKeeperMode = true;
		std::cout << "\033[0;31mScavTrap " + _name << " is now in Gate keeper mode.\033[0m"
		<< std::endl;
	}
}