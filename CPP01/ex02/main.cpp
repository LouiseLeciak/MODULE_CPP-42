/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:27:55 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 17:23:02 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string	&stringREF = *stringPTR;

	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}