/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:41 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/04 15:09:19 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stack>
#include <iostream>

int parseInput(std::string input){
	int i = 0;
	int len = input.size();
	while (i < len){
		if (input[i] < '0' || input[i] > '9'){
			if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '\"' && input[i] != ' '){
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int	getNbStack(std::string input){
	std::stack<char> calcul;
	if (parseInput(input) == -1){
		std::cerr << "invalid input" << std::endl;
		return (-1);
	}
	// proteger les divisions par 0
	// proteger si + de deux chiffres avant l'operateur
	return (0);
}