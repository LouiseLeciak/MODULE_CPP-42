/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:09:03 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/10 10:03:44 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:

	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	
	private:
	
	std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

# endif