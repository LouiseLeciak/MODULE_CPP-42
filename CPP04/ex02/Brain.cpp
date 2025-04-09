/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:10:17 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 10:13:02 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	return;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	(*this) = copy;
}


Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
	return;
}


Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "Brain: Copy assignement operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return (*this);
}