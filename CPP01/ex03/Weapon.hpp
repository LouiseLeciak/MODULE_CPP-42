/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:43:21 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/25 17:06:11 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
	
	Weapon();
	Weapon(std::string wType);
	~Weapon();
	const std::string& 	getType();
	void				setType(std::string newValue);
	
	private:
	
	std::string _type;

};

#endif