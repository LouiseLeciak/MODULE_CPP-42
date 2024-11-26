/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:00:29 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 17:19:38 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	std::stringstream	newName;
	if (N <= 0)
	{
		std::cout << "error." << std::endl;
		return (NULL);
	}
	Zombie	*zombieHorde = new Zombie[N]; 
	
	for (int i = 0; i < N; i++)
	{
		newName.str("");
		newName << name << i;
		zombieHorde[i].setName(newName.str());
	}
	return (zombieHorde);
}