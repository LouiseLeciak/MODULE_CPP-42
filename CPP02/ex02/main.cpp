/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:56:47 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/21 11:19:10 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << a.max( a, b ) << std::endl;

	// return 0;
	
	
	Fixed a = 15;
	Fixed b = 5;

	std::cout << "a: " << a << " || b: " << b << "\n" << std::endl;

	std::cout << "COMPARISON OPERATORS\n" << std::endl;

	if (a < b)
		std::cout << "a < b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;

	std::cout << std::endl;
	std::cout << "ARITHMETIC OPERATORS\n" << std::endl;
	

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	std::cout << std::endl;
	std::cout << "INCREMENT - DECREMENT\n" << std::endl;


	std::cout << "a = " << a << std::endl;
	a++;
	std::cout << "a++ = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	b--;
	std::cout << "b-- = " << b << std::endl;

	a = 15;
	b = 5;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "--b = " << --b << std::endl;

	a = 15;
	b = 5;
	std::cout << std::endl;
	std::cout << "MIN - MAX\n" << std::endl;
	
	std::cout << "max is: " << a.max( a, b ) << std::endl;
	std::cout << "min in: " << a.min( a, b ) << std::endl;

	return 0;
}