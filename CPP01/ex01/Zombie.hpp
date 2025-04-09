/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:09:03 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/25 12:05:07 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:

	Zombie();
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
	
	private:
	
	std::string	_name;
};

Zombie* zombieHorde(int N, std::string name);

# endif