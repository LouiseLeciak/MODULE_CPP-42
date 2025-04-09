/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:44:10 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/19 13:52:56 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void){
    uintptr_t   raw;
    Data*       ptr;

	Data		data;

	data.i = 42;
	data.c = ')';
	data.str  = "Hello world !";

	std::cout << "data.i: " << data.i << std::endl;
	std::cout << "data.c: " << data.c << std::endl;
	std::cout << "data.str: " << data.str << "\n\n" << std::endl;


	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);

	std::cout << "ptr->i: " << ptr->i << std::endl;
	std::cout << "ptr->c: " << ptr->c << std::endl;
	std::cout << "ptr->str: " << ptr->str << std::endl;
	std::cout << "ptr: " << ptr << std::endl;

}