/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:41 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/09 10:54:28 by lleciak          ###   ########.fr       */
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
			if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != ' '){
				return (-1);
			}
		}
		else if (input[i] >= '0' && input[i] <= '9' && input[i + 1] != ' ')
			return (-1);
		i++;
	}
	return (0);
}


bool	isANb(char c){
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	isAnOp(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}


int	calcul(int a, int b, char op){
	if (op == '+')
		return (b + a);
	if (op == '-')
		return (b - a);
	if (op == '*')
		return (b * a);
	if (op == '/'){
		if (b == 0 || a == 0){
			std::cout << "Error: Impossible operation." << std::endl;
			return (-1);
		}
		return (b / a);
	}
	else{
		std::cout << "Error: Wrong operator." << std::endl;
		return (-1);
	}
}


int	getNbStack(std::string input){
	std::stack<int>		nb;
	int					res;
	int 				len = input.size();
	int					i = 0;
	
	if (parseInput(input) == -1){
		std::cout << "invalid input" << std::endl;
		return (-1);
	}
	while (i <= len){
		if (input[i] == ' ' || input[i] == '\"'){
			i++;	
			continue;
		}
		else if (isANb(input[i]))
			nb.push(input[i] - '0');
		else if (isAnOp(input[i]) && !isAnOp(input[i + 1])){
			if (nb.size() < 2){
				std::cout << "invalid input" << std::endl;
				return (-1);
			}
			int a = nb.top();
			nb.pop();
			int b = nb.top();
			nb.pop();
			res = calcul(a, b, input[i]);
			if (res == -1)
				return(-1);
			nb.push(res);
		}
		i++;
	}
	std::cout << nb.top() << std::endl;
	return (0);
}