/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/18 09:39:52 by lleciak          ###   ########.fr       */
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