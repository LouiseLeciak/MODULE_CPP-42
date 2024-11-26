/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:38:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 17:44:05 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_allLevels[0].fonction = &Harl::debug;
	_allLevels[0].level = "DEBUG";
	
	_allLevels[1].fonction = &Harl::info;
	_allLevels[1].level = "INFO";

	_allLevels[2].fonction = &Harl::warning;
	_allLevels[2].level = "WARNING";
	
	_allLevels[3].fonction = &Harl::error;
	_allLevels[3].level = "ERROR";

	
	return;
}

Harl::~Harl()
{
	return;
}

void	Harl::debug(void)
{
	std::cout << "complain = debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "complain = info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "complain = warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "complain = error" << std::endl;
}

Harl::fptr Harl::findByLevel(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if(_allLevels[i].level == level)
			return _allLevels[i].fonction;
	}
	return (NULL);
}

void Harl::complain(std:: string level)
{
	fptr find = findByLevel(level);
	(this->*find)();
} 