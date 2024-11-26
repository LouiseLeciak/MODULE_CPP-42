/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:38:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/01 11:07:15 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	allLevels[0].fonction = &Harl::debug;
	allLevels[0].level = "DEBUG";
	
	allLevels[1].fonction = &Harl::info;
	allLevels[1].level = "INFO";

	allLevels[2].fonction = &Harl::warning;
	allLevels[2].level = "WARNING";
	
	allLevels[3].fonction = &Harl::error;
	allLevels[3].level = "ERROR";

	
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
		if(allLevels[i].level == level)
		return allLevels[i].fonction;
	}
	return (NULL);
}

void Harl::complain(std::string level)
{
	fptr find = findByLevel(level);
	(this->*find)();

}

void Harl::newComplain(std::string loglevel)
{
	int i = 0;
	const std::string complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 5)
	{
		if (i == 4)
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ;
		}
		if (complain[i] == loglevel)
			break;
		i++;
	}

	switch (i)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
		default:
			break;

	}
}