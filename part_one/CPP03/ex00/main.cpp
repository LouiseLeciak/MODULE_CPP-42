/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:11:55 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/29 08:40:12 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


////////////////////////////
//with default constructor//
////////////////////////////
int	main()
{
	ClapTrap bot;
	
	bot.attack("Psycho");
	
	bot.takeDamage(3);
	bot.beRepaired(2);
	
	bot.takeDamage(5);
	bot.beRepaired(3);

	bot.attack("Psycho");
	return (0);
}




////////////////////
//copy constructor//
////////////////////
// int	main()
// {
// 	ClapTrap bot("Michel");
// 	ClapTrap dude(bot);

	
// 	dude.attack("Psycho");
	
// 	dude.takeDamage(3);
// 	dude.beRepaired(2);
	
// 	dude.takeDamage(5);
// 	dude.beRepaired(3);

// 	dude.attack("Psycho");
// 	return (0);
// }





/////////////////
//copy operator//
/////////////////
// int	main()
// {
// 	ClapTrap bot("Michel");
// 	ClapTrap dude;

// 	dude = bot;
	
// 	dude.attack("Psycho");
	
// 	dude.takeDamage(3);
// 	dude.beRepaired(2);
	
// 	dude.takeDamage(5);
// 	dude.beRepaired(3);

// 	dude.attack("Psycho");
// 	return (0);
// }


/////////////////////////
//with name constructor//
/////////////////////////
// int	main()
// {
// 	ClapTrap bot("CL4P-TP");

// 	bot.attack("Psycho");
	
// 	bot.takeDamage(3);
// 	bot.beRepaired(2);
	
// 	bot.takeDamage(5);
// 	bot.beRepaired(3);

// 	bot.attack("Psycho");
// 	return (0);
// }






//////////////////
//no more energy//
//////////////////
// int	main()
// {
// 	ClapTrap bot("CL4P-TP");

// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");
// 	bot.attack("Psycho");	

// 	return (0);
// }






//////////////////
//no more health//
//////////////////
// int	main()
// {
// 	ClapTrap bot("CL4P-TP");

// 	bot.attack("Psycho");
	
// 	bot.takeDamage(8);
// 	bot.beRepaired(2);
	
// 	bot.takeDamage(5);
// 	bot.attack("Psycho");
// 	bot.beRepaired(3);

// 	return (0);
// }