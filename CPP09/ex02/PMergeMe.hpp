/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:06:03 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/07 13:07:28 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

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

std::vector<IntPair> insert_v(std::vector<IntPair> main, std::vector<IntPair> pending);
std::vector<IntPair> pendingManagement_v(std::vector<IntPair> pending);
void sort_v(std::vector<IntPair>& input);

std::deque<IntPair> insert_d(std::deque<IntPair> main, std::deque<IntPair> pending);
std::deque<IntPair> pendingManagement_d(std::deque<IntPair> pending);
void sort_d(std::deque<IntPair>& input);

#endif

