/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:02:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/25 17:35:54 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon& weapon);
	
	private:
	
	std::string _name;
	Weapon*		_weapon;

};

#endif