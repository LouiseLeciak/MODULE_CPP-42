/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:59:16 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 06:43:49 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CLAPTRAP_HPP
# define 	CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
	
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& copy);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	protected:
	
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

//private - members cannot be accessed (or viewed) from outside the class. 
//protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

#endif