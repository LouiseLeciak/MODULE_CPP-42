/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:52:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 07:49:47 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[0;35mFragTrap created. It's name is \033[0m" << this->_name << std::endl;
	std::cout<< std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[0;35mFragTrap created. It's  name is \033[0m" << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "\033[0;35mCopy FragTrap\033[0m" << std::endl;
	this->_name = copy._name;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "\033[0;35mCopy FragTrap using =\033[0m" << std::endl;
	this->_name = copy._name;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << std::endl;
	std::cout << "\033[0;35mFragTrap destroyed.\033[0m" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "\033[0;35mFragTrap want to do a high fives.\033[0m" << std::endl;
	std::cout << "🫸 💥 🫷" << std::endl;
}
