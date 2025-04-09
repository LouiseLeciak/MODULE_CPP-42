/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:11:55 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/29 08:49:39 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"


////////////
//FragTrap//
////////////
int	main()
{
	FragTrap a;
	FragTrap b("FR4G-TP");

	a.attack("PSYCHO");
	a.beRepaired(22);
	a.takeDamage(21);
	a.beRepaired(22);
	a.highFivesGuys();
	
	b.attack("PSYCHO");
	b.takeDamage(101);
	b.takeDamage(15);
	b.attack("PSYCHO");
	b.highFivesGuys();
	b.beRepaired(5);

	return (0);
}


////////////
//ClapTrap//
////////////
// int	main()
// {
// 	ClapTrap a;
// 	ClapTrap b("CL4P-TP");

// 	a.attack("PSYCHO");
// 	a.takeDamage(10);
// 	a.takeDamage(10);
// 	a.beRepaired(5);
// 	a.attack("PSYCHO");
	
// 	std::cout << std::endl;
	
// 	b.beRepaired(3);
// 	b.beRepaired(3);
// }