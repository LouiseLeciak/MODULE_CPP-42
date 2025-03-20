/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:24:51 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/04 14:45:32 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char *av[]){
	if (ac != 2){
		std::cout << "invalid parametres" << std::endl;
	}
	getNbStack(av[1]);
}