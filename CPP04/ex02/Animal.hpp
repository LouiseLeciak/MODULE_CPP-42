/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:15:59 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:43:52 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef 	ANIMAL_HPP
# define 	ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
	
	virtual ~Animal();

	std::string	getType();
	virtual void	makeSound(void) = 0;

	protected:
	
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		std::string	_type;

};


#endif