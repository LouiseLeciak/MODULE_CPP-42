/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/19 14:34:16 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> 
#include "../inc/Array.hpp"


int main(void)
{
	try
	{
		std::cout << "STRING ARRAY" << std::endl;
		
		Array<std::string> strArray(3);
		strArray[1] = "Youpi";
		std::cout << strArray[1] << std::endl;

		std::cout << "INT ARRAY" << std::endl;

		Array<int> intArray(3);
		intArray[0] = 2;
		std::cout << intArray[0] << std::endl;
		std::cout << intArray[1] << std::endl;

		// std::cout << "Test exception" << std::endl;
		// std::cout << intArray[4] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

