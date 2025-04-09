/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:58:07 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:01:32 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CAT_HPP
# define 	CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
	
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	~Cat();

	void	makeSound(void);

	private:
	
};


#endif