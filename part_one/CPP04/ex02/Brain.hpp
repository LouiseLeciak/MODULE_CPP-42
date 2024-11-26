/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:07:51 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 10:11:47 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	BRAIN_HPP
# define 	BRAIN_HPP

#include <iostream>

class Brain
{
	public:
	
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& copy);
	~Brain();

	std::string	_ideas[100];
	
};


#endif