/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:20:06 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/28 10:00:35 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/////////////////
//homemade main//
/////////////////
int	main()
{
	Animal	*ani = new Animal();
	Animal	*cat = new Cat();
	Animal	*dog = new Dog();
	
	WrongAnimal	*wa = new WrongCat();

	std::cout << "Hello, i'm a " << ani->getType() << " and i'm saying ";
	ani->makeSound();
	std::cout << std::endl;

	std::cout << "Hello, i'm a " << cat->getType() << " and i'm saying ";
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "Hello, i'm a " << dog->getType() << " and i'm saying ";
	dog->makeSound();
	std::cout << std::endl;

	std::cout << "Hello, i'm a " << wa->getType() << " and i'm saying ";
	wa->makeSound();
	std::cout << std::endl;

	delete ani;
	delete cat;
	delete dog;
	delete wa;
}




//////////////////////////////
//Sub's main w/ wrong animal//
//////////////////////////////
// int main()
// {
// 	Animal* meta = new Animal();
// 	Animal* j = new Dog();
// 	WrongAnimal* i = new WrongCat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	// delete meta;
// 	// delete j;
// 	// delete i;
// 	return 0;
// }


//////////////////
//Subject's main//
//////////////////
// int main()
// {
// 	Animal* meta = new Animal();
// 	Animal* j = new Dog();
// 	Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	// delete meta;
// 	// delete j;
// 	// delete i;
// 	return 0;
// }
