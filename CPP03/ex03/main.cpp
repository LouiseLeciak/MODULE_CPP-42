/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:11:55 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/29 08:56:18 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap bot("DI4MD-TP");
	DiamondTrap	botTwo;

	std::cout << std::endl;
	std::cout << "has inherited FragTrap's attack damage : 30." << std::endl;
	std::cout << "has inherited FragTrap's hit points : 100." << std::endl;
	std::cout << "has inherited ScavTrap's energy points : 50." << std::endl;
	std::cout << std::endl;
	
	bot.attack("Psycho");
	bot.beRepaired(10);
	
	bot.whoAmI();
	botTwo = bot;
	botTwo.whoAmI();
	
	bot.guardGate();
	bot.highFivesGuys();
	
	return (0);
}


