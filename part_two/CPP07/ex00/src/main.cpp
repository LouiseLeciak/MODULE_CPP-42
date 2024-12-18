/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/18 09:58:14 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/whatever.hpp"

int main()
{
	int a = 8;
	int b = 10;
	float c = 42.42f;
	float d = 4.5f;
	char e = 'a';
	char f = 'z';
	
	std::cout << "\033[0;35m MAX: \033[0m" << std::endl;
	
	std::cout << max<int>(a,b) << std::endl;	
	std::cout << max<float>(c,d) << std::endl;
	std::cout << max<char>(e,f) << std::endl;
	
	std::cout << "\033[0;35m MIN:  \033[0m" << std::endl;
	
	std::cout << min<int>(a,b) << std::endl;
	std::cout << min<float>(c,d) << std::endl;
	std::cout << min<char>(e,f) << std::endl;

	std::cout << "\033[0;35m SWAP:  \033[0m" << std::endl;

	std::cout << "Before swap:\na = " << a;
	std::cout << "\nb = " << b;
	std::cout << "\nc = " << c;
	std::cout << "\nd = " << d;
	std::cout << "\ne = " << e;
	std::cout << "\nf = " << f << std::endl;

	swap<int>(a,b);
	swap<float>(c,d);
	swap<char>(e,f);

	std::cout << "After swap:\na = " << a;
	std::cout << "\nb = " << b;
	std::cout << "\nc = " << c;
	std::cout << "\nd = " << d;
	std::cout << "\ne = " << e;
	std::cout << "\nf = " << f << std::endl;
}

// int main( void ) {
// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// return 0;
// }