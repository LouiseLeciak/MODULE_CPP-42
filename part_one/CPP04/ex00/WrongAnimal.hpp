/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:33:46 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 09:34:06 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	WRONGANIMAL_HPP
# define 	WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
	
	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& copy);
	~WrongAnimal();

	std::string	getType();
	void	makeSound(void);

	protected:
	
		std::string	_type;
};


#endif