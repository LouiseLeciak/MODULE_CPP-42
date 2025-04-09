/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:35:14 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/10 10:04:39 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << "New Zombie named " << name << std::endl;
	_name = name;
	return;
}

Zombie::~Zombie()
{
	std::cout<< _name << " : got back to his grave." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

