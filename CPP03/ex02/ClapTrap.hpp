/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:59:16 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 12:31:27 by lleciak          ###   ########.fr       */
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


#endif