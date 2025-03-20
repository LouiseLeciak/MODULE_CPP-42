/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/18 10:50:18 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	print(const std::string &str){
	std::cout << str << std::endl;
}

void	printInt(const int &i){
	std::cout << i << std::endl;
}

int main()
{
	std::string tab[] = {"youpi", "coucou", "hihi", "bip", "boup"};
	int intTab[] = {1, 2, 3, 4, 5};
	
	iter(tab,5,print);
	iter(intTab,5,printInt);
}