/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 08:41:05 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/19 14:15:25 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <math.h>

Base*	generate(void)
{
	std::cout << "Generate: ";
	srand(time(NULL));
	int ran = rand() % 3;
	
	if (ran == 0){
		std::cout << "A" << std::endl;
		return (new A);
	}
	else if (ran == 1){
		std::cout << "B" << std::endl;
		return (new B);
	}
	else if (ran == 2){
		std::cout << "C" << std::endl;
		return (new C);
	}
	else
		return (NULL);
};

void	identify(Base* p)
{
	std::cout << "Identification: ";

	if (A* test = dynamic_cast<A*>(p)){
		if (test == NULL){
			std::cerr << "cast error." << std::endl;
			return;
		}
		(void)test;
		std::cout << "A" << std::endl;
	}
	else if (B* test = dynamic_cast<B*>(p)){
		if (test == NULL){
			std::cerr << "cast error." << std::endl;
			return;
		}
		(void)test;	
		std::cout << "B" << std::endl;
	}
	else if (C* test = dynamic_cast<C*>(p)){
		if (test == NULL){
			std::cerr << "cast error." << std::endl;
			return;
		}
		(void)test;
		std::cout << "C" << std::endl;
	}
	else
		std::cout << "error" << std::endl;
};

void	identify(Base& p)
{
	std::cout << "Identify &: ";
	try {
    	A& test = dynamic_cast<A &>(p);
		(void)test;
		std::cout << "A" << std::endl;
	} 
	catch(const std::exception &e) {}
	try {
    	B& test = dynamic_cast<B &>(p);
		(void)test;
		std::cout << "B" << std::endl;
	} 
	catch(const std::exception &e) {}
	try {
    	C& test = dynamic_cast<C &>(p);
		(void)test;
		std::cout << "C" << std::endl;
	} 
	catch(const std::exception &e) {}
};