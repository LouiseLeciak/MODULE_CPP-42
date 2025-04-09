/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:20:06 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 14:50:55 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



int	main()
{
	//Animal	*ani = new Animal();
	Animal	*cat = new Cat();
	Animal	*dog = new Dog();

	// std::cout << "Hello, i'm a " << ani->getType() << " and i'm saying ";
	// ani->makeSound();
	// std::cout << std::endl;

	std::cout << "Hello, i'm a " << cat->getType() << " and i'm saying ";
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "Hello, i'm a " << dog->getType() << " and i'm saying ";
	dog->makeSound();
	std::cout << std::endl;

	//delete ani;
	delete cat;
	delete dog;
}
