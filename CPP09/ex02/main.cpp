/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:06:51 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/14 09:35:19 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ctime>


int	parseInput(int ac, char *av[]){
	if (ac == 1)
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
	
	std::vector<long unsigned int> input;
	for (int i = 1; av[i]; i++)
		input.push_back(std::atoi(av[i]));
	if (checkDouble(input) == -1){
		std::cout << "Double not allowed." << std::endl;
		return (-1);
	}
	std::vector<IntPair> sorted_v;
	std::deque<IntPair> sorted_d;

	
	for (unsigned long i = 0; i < input.size(); i++){
		sorted_v.push_back(IntPair(input[i], i));
		sorted_d.push_back(IntPair(input[i], i));
	}
	
	std::cout << "Before: ";
	for (unsigned long i = 0; i < input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	
	//////////////////
	//time and print//
	//////////////////
	
    const std::clock_t c_start_vec = std::clock();
    sort_v(sorted_v);    
    const std::clock_t c_end_vec = std::clock();

    std::cout << std::endl;
    std::cout << "VEC After:  ";
   	for (unsigned long i = 0; i < sorted_v.size(); i++)
		std::cout << sorted_v[i].value << " ";
	std::cout << std::endl;
    
    const std::clock_t c_start_lst = std::clock();
    sort_d(sorted_d);
    const std::clock_t c_end_lst = std::clock();

    
    std::cout << std::endl;

    std::cout << "DEQUE After:  ";
    	for (unsigned long i = 0; i < sorted_d.size(); i++)
		std::cout << sorted_d[i].value << " ";
	std::cout << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << ac - 1 << " elements with std::vector: " << (double) (c_end_vec - c_start_vec) / CLOCKS_PER_SEC << " ms" << std::endl;
    std::cout << std::fixed << std::setprecision(5) <<  "Time to process a range of " << ac - 1 << " elements with std::deque:   " << (double) (c_end_lst - c_start_lst) / CLOCKS_PER_SEC << " ms" << std::endl;

	return(0);
}