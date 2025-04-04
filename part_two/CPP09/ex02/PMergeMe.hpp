/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:06:03 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/04 23:28:35 by lleciak          ###   ########.fr       */
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
		IntPair(long unsigned int v, long unsigned int i){
			value = v;
			index = i;
		};
		long unsigned int value;
		long unsigned int index; 

};

std::vector<IntPair> insert(std::vector<IntPair> main, std::vector<IntPair> pending);
std::vector<IntPair> pendingManagement(std::vector<IntPair> pending);
void sort(std::vector<IntPair>& input);



#endif

