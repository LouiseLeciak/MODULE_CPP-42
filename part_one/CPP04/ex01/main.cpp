/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:20:06 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/31 07:51:00 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/////////////////
//homemade main//
/////////////////
int	main()
{
	Animal	*PawPatrol[10];
	for (int i = 0; i <= 4; i++)
		PawPatrol[i] = new Cat();
	for (int i = 5; i < 10; i++)
		PawPatrol[i] = new Dog();

	std::cout << "\n-----Pawpatrol-----\n" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Hi, I am " << PawPatrol[i]->getType() << " "
		<< i << std::endl;
	}

	std::cout << "\n\n-----Destructor-----\n" << std::endl;

	for (int i = 0; i < 10; i++)
		delete PawPatrol[i];
}



//////////////////
//Subject's main//
//////////////////
// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
	
// 	delete j;//should not create a leak
// 	delete i;
	
// 	return 0;
// }
