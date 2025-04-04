/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:06:03 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/04 13:24:32 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <sys/time.h>
#include <iostream>

class IntPair 
{ 
	public:
		IntPair(int v, int i){
			value = v;
			index = i;
		};
		int value;
		int index; 

};

std::vector<int> insert(std::vector<int> main, std::vector<IntPair> pending);
std::vector<IntPair> pendingManagement(std::vector<int> pending);
std::vector<IntPair> sort(std::vector<int> input);



#endif

