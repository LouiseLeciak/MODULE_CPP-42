/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:01:48 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/25 17:34:28 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
	
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
	
	private:
	
	std::string _name;
	Weapon& 	_weapon;

};

#endif