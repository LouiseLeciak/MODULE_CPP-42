/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:20:06 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 15:14:12 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main()
{
	{
	std::cout << "\033[0;35m* * * SUBJECT'S MAIN * * *\033[0m\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	}
	
	{
	std::cout << "\n\033[0;35m* * * ANOTHER SUBJECT * * *\033[0m\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Philou");
	AMateria* tmp;
	AMateria* save;
	AMateria* save1;
	
	tmp = src->createMateria("ice");
	save = tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	save1 = tmp;
	me->equip(tmp);
	
	std::cout << "\n\033[0;35m* * * USING FIREBALL * * *\033[0m\n" << std::endl;
	tmp = src->createMateria("FIREBALL");
	
	ICharacter* bob = new Character("Gale");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << "\n\033[0;35m* * * USING UNEQUIP WITH INVALID INDEX * * *\033[0m\n" << std::endl;
	
	me->unequip(9);
	std::cout << "OK" << std::endl;


	std::cout << "\n\033[0;35m* * * USING UNEQUIP * * *\033[0m\n" << std::endl;

	me->unequip(0);
	me->unequip(1);
	
	std::cout << "\n\033[0;35m* * * USING WITHOUT CREATE * * *\033[0m\n" << std::endl;


	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << "OK\n" << std::endl;


	delete save;
	delete save1;
	delete bob;
	delete me;
	delete src;
	}

	return 0;
}
