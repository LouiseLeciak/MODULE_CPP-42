/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:06:51 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/04 13:53:23 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <cstdlib>

// parser de l'input, que des chiffres, pas de doublon, si doublon = erreur
int	parseInput(int ac, char *av[]){
	if (ac == 1) // si pas de num
		return (-1);
	for (int i = 1; av[i]; i++){
		for (int j = 0; av[i][j]; j++){
			if (av[i][j] < 48 || av[i][j] > 57)
				return (-1);
		}
	}
	return (1);
}

int	checkDouble(std::vector<long unsigned int> input){
	std::vector<long unsigned int> tmp = input;
	for(long unsigned int i = 0; i < input.size(); i++){
		for (long unsigned int j = 0; j < tmp.size(); j++){
			if (i != j && input[i] == tmp[j])
				return (-1);
		}
	}
	return (0);
}


int main(int ac, char *av[]){
	if (parseInput(ac, av) == -1){
		std::cout << "Invalid input." << std::endl;
		return (-1);
	}
	if (ac == 2){
		std::cout << av[1] << std::endl;
	}
	
	std::vector<long unsigned int> input;
	for (int i = 1; av[i]; i++){
		input.push_back(std::atoi(av[i]));
	}
	if (checkDouble(input) == -1){
		std::cout << "Double not allowed." << std::endl;
		return (-1);
	}
	
	std::vector<IntPair> sorted = sort(input);

	// time management
	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	gettimeofday(&tv2, NULL);
	double time1 = (double) (tv2.tv_sec - tv1.tv_sec);
	time1 = (double) ((time1 * 1000000) + (tv2.tv_usec - tv1.tv_usec));
	std::cout << "Time to process a range of " << sorted.size() << " elements";
	std::cout << " with std::vector :  " << time1 << " us" << std::endl;

	
	//print juste le vector sorted
	for (unsigned long i = 0; i < sorted.size(); i++)
		std::cout << sorted[i].value << " ";
	std::cout << std::endl;
	return(0);
}