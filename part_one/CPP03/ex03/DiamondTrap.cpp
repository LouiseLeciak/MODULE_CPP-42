/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:25:19 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/25 11:55:44 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "Default";
	this->ClapTrap::_name = "Default_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	
	std::cout << "\033[0;34mDiamondTrap created. It's name is \033[0m" << this->_name << std::endl;
	std::cout<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	// clap scav frag up pour ne pas instancier de classe
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	
	std::cout << "\033[0;34mDiamondTrap created. It's  name is \033[0m" << this->_name << std::endl;
	this->_name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout << "\033[0;34mCopy DiamondTrap\033[0m" << std::endl;
	this->_name = copy._name;
	this->ClapTrap::_name = copy.ClapTrap::_name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "\033[0;34mCopy DiamondTrap using =\033[0m" << std::endl;
	this->_name = copy._name;
	this->ClapTrap::_name = copy.ClapTrap::_name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << std::endl;
	std::cout << "\033[0;34mDiamondTrap destroyed.\033[0m" << std::endl;
}


void	DiamondTrap::whoAmI()
{
	std::cout << "\033[0;34mDiamondTrap's name is \033[0m" << _name
	<< std::endl;
	std::cout << "\033[0;34mDiamondTrap's ClapTrap name is \033[0m" << ClapTrap::_name
	<< std::endl;
	

}
