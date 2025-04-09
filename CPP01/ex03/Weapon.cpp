/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:44:24 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/25 17:17:29 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	return;
}

Weapon::Weapon(std::string wType)
{
	_type = wType;
	return;
}

Weapon::~Weapon()
{
	return;
}

const std::string& Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string newValue)
{
	_type = newValue;
}
