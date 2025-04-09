/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:23:01 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/09 11:59:44 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>


IntPair::IntPair(){};
IntPair::~IntPair(){};
IntPair::IntPair(const IntPair &copy){
	(*this) = copy;
};

IntPair &IntPair::operator=(const IntPair &copy){
	value = copy.value;
	index = copy.index;
	return (*this);
};

IntPair::IntPair(long unsigned int v, long unsigned int i){
	value = v;
	index = i;
};


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////STD::VECTOR/////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// insert pendings with a binary search;
std::vector<IntPair> insert_v(std::vector<IntPair> main, std::vector<IntPair> pending){

	for (long unsigned int i = 0; i < pending.size(); i++){
		IntPair current = pending[i];// current is the object we are testing, looking for when it's supposed to og
		long unsigned int high = main.size(); 
		long unsigned int  low = 0;
		long unsigned int  mid = 0;
		
		while (low <= high) {

        	mid = low + (high - low) / 2;
			if (mid == main.size() - 1 && current.value > main[main.size() - 1].value){
				mid++;
				break;
			}
			if (mid == 0){
				if (current.value < main[0].value)
					break;
				mid++;
			}
			if ((current.value > main[mid - 1].value && current.value < main[mid].value))
				break;
			if (current.value > main[mid].value)
				low = mid + 1;
			if (current.value < main[mid].value)
				high = mid - 1;

    	}
		//main.insert(where, what);
		main.insert(main.begin() + mid, current);
	}
	return (main);
}


// sort pending with Jacobsthal and indexes
std::vector<IntPair> pendingManagement_v(std::vector<IntPair> pending){
	std::vector<long unsigned int> Jacobsthal;
	long unsigned int j = 1;
	long unsigned int prec = 1;
	for (int i = 0; j <= pending.size(); i++){ // saving the jacobsthal suit in a vector
		int temp;
		Jacobsthal.push_back(j);
		temp = j;
		j = j + prec + prec;
		prec = temp;
	}
	int tmp;
	Jacobsthal.push_back(j);
	tmp = j;
	j = j + prec + prec;
	prec = tmp;

	std::vector<IntPair> pendingFinal;
	long unsigned int jacobPrecIt = 0;// precedent jacob
	int	jacobIt = 1;//iterator jacob
	int	comp = 0;
	while (pendingFinal.size() != pending.size() - 1){
		long unsigned int index = Jacobsthal[jacobIt] - comp++;
		if (index > pending.size()){;
			continue;
		}
		if (index <= Jacobsthal[jacobPrecIt]){ // if at 11, to do the missing ones 9,8,7,6,5..
			jacobPrecIt = jacobIt;
			index = Jacobsthal[++jacobIt];
			comp = 0;
			continue;	
		}
		// here -1 bcs first math index = 1
		pendingFinal.push_back(IntPair(pending[index - 1].value, pending[index - 1].index));
	}
	return (pendingFinal);
}



// sort input using ford johnson index
// void bcs using a reference to modify input directly;
void sort_v(std::vector<IntPair>& input){
	if (input.size() == 2){ //sort for 2 
		if (input[0].value > input[1].value){
			std::swap(input[0], input[1]);
		}
		return;
	}

	if(input.size() == 1){
		return;
	}

	std::vector<IntPair> main;
	std::vector<IntPair> pending;
	int iterator = 0;
	
	// making the pair, main and pending
	if (input.size() % 2 == 1){ // if there is an odd number of input
		for (long unsigned int i = 0; i < input.size() - 1; i++){
			if (i % 2 == 1)
				pending.push_back(IntPair(input[i].value, input[i].index));
			else
				main.push_back(IntPair(input[i].value, iterator++));
		}
		pending.push_back(IntPair(input.back().value, input.back().index)); //then the last on go with pendings
	}
	else{ // even number in input
		for (long unsigned int i = 0; i < input.size(); i++){
			if (i % 2 == 1)
				pending.push_back(IntPair(input[i].value, input[i].index));
			else
				main.push_back(IntPair(input[i].value, iterator++));
		}
	}

	for (long unsigned int i = 0; i < main.size(); i++){ // sort INSIDE PAIRS
		if (pending[i].value > main[i].value){
			int tmp = pending[i].value;
			pending[i].value = main[i].value;
			pending[i].index = input[i*2].index;// i * 2 because pendings = 1 on 2 in principal input chain
			main[i].value = tmp;
		}
	}
	
	sort_v(main); // recursively sort
	
	// we organize pending like we did with main
	std::vector<IntPair> copyPending = pending;
	
		
	for(long unsigned int i = 0; i < main.size(); i++){
		pending[i] = copyPending[main[i].index];
	}

	// for each main we're searching in input for the original index
	for(unsigned long int i = 0; i < main.size(); i ++)
	{
		for (unsigned long int j = 0; j<input.size(); j++)
		{
			if(input[j].value == main[i].value)
				main[i].index = input[j].index;
		}
	}
	
	main.insert(main.begin(), IntPair(pending[0])); // insert the little of the first duo because we know it's smaller than all the main

	// then we sort pending in the jacobsthal sequence
	std::vector<IntPair> newPending = pendingManagement_v(pending);

	// and we insert pending using binary search
	main = insert_v(main, newPending);
	
	// giving the sorted container to input bcs it's a ref
	for (long unsigned int i = 0; i < main.size(); i++)
		input[i]= main[i];
}




////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//////////////////////////////////STD::LIST/////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


std::deque<IntPair> insert_d(std::deque<IntPair> main, std::deque<IntPair> pending){

	for (long unsigned int i = 0; i < pending.size(); i++){
		IntPair current = pending[i];
		long unsigned int high = main.size();
		long unsigned int  low = 0;
		long unsigned int  mid = 0;
		
		while (low <= high) {

        	mid = low + (high - low) / 2;
			if (mid == main.size() - 1 && current.value > main[main.size() - 1].value){
				mid++;
				break;
			}
			if (mid == 0){
				if (current.value < main[0].value)
					break;
				mid++;
			}
			if ((current.value > main[mid - 1].value && current.value < main[mid].value))
				break;
			if (current.value > main[mid].value)
				low = mid + 1;
			if (current.value < main[mid].value)
				high = mid - 1;

    	}
		main.insert(main.begin() + mid, current);
	}
	return (main);
}



std::deque<IntPair> pendingManagement_d(std::deque<IntPair> pending){
	std::deque<long unsigned int> Jacobsthal;
	long unsigned int j = 1;
	long unsigned int prec = 1;
	for (int i = 0; j <= pending.size(); i++){
		int temp;
		Jacobsthal.push_back(j);
		temp = j;
		j = j + prec + prec;
		prec = temp;
	}
	int tmp;
	Jacobsthal.push_back(j);
	tmp = j;
	j = j + prec + prec;
	prec = tmp;

	std::deque<IntPair> pendingFinal;
	long unsigned int jacobPrecIt = 0;
	int	jacobIt = 1;
	int	comp = 0;
	while (pendingFinal.size() != pending.size() - 1){
		long unsigned int index = Jacobsthal[jacobIt] - comp++;
		if (index > pending.size()){;
			continue;
		}
		if (index <= Jacobsthal[jacobPrecIt]){
			jacobPrecIt = jacobIt;
			index = Jacobsthal[++jacobIt];
			comp = 0;
			continue;	
		}

		pendingFinal.push_back(IntPair(pending[index - 1].value, pending[index - 1].index)); // pendingcopy c'est les pending range en combinaison de jacob + index
	}
	return (pendingFinal);
}


void sort_d(std::deque<IntPair>& input){
	if (input.size() == 2){ //sort pour 2 
		if (input[0].value > input[1].value){
			std::swap(input[0], input[1]);
		}
		return;
	}

	if(input.size() == 1){
		return;
	}

	std::deque<IntPair> main;
	std::deque<IntPair> pending;
	int iterator = 0;
	

	if (input.size() % 2 == 1){
		for (long unsigned int i = 0; i < input.size() - 1; i++){
			if (i % 2 == 1)
				pending.push_back(IntPair(input[i].value, input[i].index));
			else
				main.push_back(IntPair(input[i].value, iterator++));
		}
		pending.push_back(IntPair(input.back().value, input.back().index));
	}
	else{ // nombre pair d'input
		for (long unsigned int i = 0; i < input.size(); i++){
			if (i % 2 == 1)
				pending.push_back(IntPair(input[i].value, input[i].index));
			else
				main.push_back(IntPair(input[i].value, iterator++));
		}
	}

	for (long unsigned int i = 0; i < main.size(); i++){
		if (pending[i].value > main[i].value){
			int tmp = pending[i].value;
			pending[i].value = main[i].value;
			pending[i].index = input[i*2].index;
			main[i].value = tmp;
		}
	}
	sort_d(main);
	
	std::deque<IntPair> copyPending = pending;
	
		
	for(long unsigned int i = 0; i < main.size(); i++){
		pending[i] = copyPending[main[i].index];
	}

	for(unsigned long int i = 0; i < main.size(); i ++)
	{
		for (unsigned long int j = 0; j<input.size(); j++)
		{
			if(input[j].value == main[i].value)
				main[i].index = input[j].index;
		}
	}
	
	main.push_front(IntPair(pending[0]));
	
	std::deque<IntPair> newPending = pendingManagement_d(pending);

	main = insert_d(main, newPending);
	
	for (long unsigned int i = 0; i < main.size(); i++)
		input[i]= main[i];
}