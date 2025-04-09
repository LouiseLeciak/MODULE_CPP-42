/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:08:49 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:05:49 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 20;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "\033[0;33mNew ClapTrap created, it's name is \033[0m" << _name << std::endl;
	std::cout << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\033[0;33mNew ClapTrap created, it's name is \033[0m" << name << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "\033[0;33mClapTrap copy.\033[0m" << std::endl;
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	this->_name = copy._name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "\033[0;33mClapTrap copy using =.\033[0m" << std::endl;
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	this->_name = copy._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl;
	std::cout << "\033[0;33mClapTrap destroyed.\033[0m" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		std::cout << "\033[0;33mClapTrap " << this->_name << " is too tired to attack..\033[0m" << std::endl;
	else
	{
		std::cout << "\033[0;33mClapTrap " << this->_name << " attacks " << target
				  << " causing " << this->_attackDamage << " points of damage !\033[0m" << std::endl;
		this->_energyPoints--;
	}
	std::cout << "\033[0;33mClapTrap " << this->_name << " now has " << this->_energyPoints 
	<< " energy points.\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[0;33mClapTrap " << this->_name << " takes " << amount << " damages !\033[0m" << std::endl;
	if (amount > (unsigned int)this->_hitPoints)
		std::cout << "\033[0;33mClapTrap " << this->_name << " is not in good shape.. repairs needed\033[0m"<< std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "\033[0;33mClapTrap " << this->_name << " now has " << this->_hitPoints << " hit points.\033[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		std::cout << "\033[0;33mClapTrap " << this->_name << " is too tired to repair..\033[0m" << std::endl;
	else
	{
		std::cout << "\033[0;33mClapTrap " << this->_name << " repairs itself and gets " << amount
				  << " hit points back.\033[0m" << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
	std::cout << "\033[0;33mClapTrap " << this->_name << " now has " << this->_energyPoints << " energy points.\033[0m" << std::endl;
	std::cout << "\033[0;33mClapTrap " << this->_name << " now has " << this->_hitPoints << " hit points.\033[0m" << std::endl;
}
