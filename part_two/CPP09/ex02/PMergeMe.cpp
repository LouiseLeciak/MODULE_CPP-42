/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:23:01 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/04 20:35:31 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"


// inserer les pendings dans le main avec un binary search;
std::vector<long unsigned int> insert(std::vector<long unsigned int> main, std::vector<IntPair> pending){

	for (long unsigned int i = 0; i < pending.size(); i++){
		long unsigned int current = pending[i].value;// objet qu'on test, savoir ou on le met
		long unsigned int high = main.size(); // aller au milieu du tableau
		long unsigned int  low = 0;
		long unsigned int  mid = 0;
		while (low <= high) {
        	mid = low + (high - low) / 2;
			if (mid == main.size() - 1 && current > main[main.size() - 1]){
				mid++;
				break;
			}
			if (mid == 0){
				if (current < main[0])
					break;
				mid++;
			}
			if ((current > main[mid - 1] && current < main[mid]))
				break;
			if (current > main[mid])
				low = mid;
			if (current < main[mid])
				high = mid;

    	}
		//main.insert(position, quoi);
		main.insert(main.begin() + mid, current);
	}
	return (main);
}


// trier pending dans l'order jacob + index
std::vector<IntPair> pendingManagement(std::vector<long unsigned int> pending){
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
		if (index <= Jacobsthal[jacobPrecIt]){ // si on arrive a 11, pour faire tt ceux qui manque 9,8,7,6,5..
			jacobPrecIt = jacobIt;
			index = Jacobsthal[++jacobIt];
			comp = 0;
			continue;	
		}
		
		pendingFinal.push_back(IntPair(pending[index - 1], index - 1)); // pendingcopy c'est les pending range en combinaison de jacob + index
	}
	return (pendingFinal);
}



// sort l'input selon l'algo de Ford Johnson
std::vector<IntPair> sort(std::vector<long unsigned int> input){
	if (input.size() <= 2){ //sort pour 2 
		std::vector<IntPair> pair;
		pair.push_back(IntPair(input[0], 0));
		if (input.size() == 1)
			return (pair);
		pair.push_back(IntPair(input[1], 1));
		if (input[0] > input[1]){
			std::vector<IntPair> tmp;
			tmp.push_back(pair[1]);
			pair[1] = pair[0];
			pair[0] = tmp[0];
		}
		return (pair);
	}

	std::vector<long unsigned int> main;
	std::vector<long unsigned int> pending;
	std::vector<IntPair> sorted;
	// ranger les main et les pending
	if (input.size() % 2 == 1){ // si un nombre impaire d'input donc un boloss
		for (long unsigned int i = 0; i < input.size() - 1; i++){
			if (i % 2 == 1)
				pending.push_back(input[i]);
			else
				main.push_back(input[i]);
		}
		pending.push_back(input.back());
	}
	else{ // nombre pair d'input
		for (long unsigned int i = 0; i < input.size(); i++){
			if (i % 2 == 1)
				pending.push_back(input[i]);
			else
				main.push_back(input[i]);
		}
	}

	for (long unsigned int i = 0; i < main.size(); i++){
		if (pending[i] > main[i]){// sort IN PAIRS
			// std::vector<int> tmp;
			// tmp.push_back(pending[i]);
			int tmp = pending[i];
			pending[i] = main[i];
			main[i] = tmp;
		}
	}

	sorted = sort(main);
	// we organize pending like we did with main
	std::vector<long unsigned int> copyPending = pending;
	
	for(long unsigned int i = 0; i < main.size(); i++){
		main[i] = sorted[i].value;
		pending[i] = copyPending[sorted[i].index];
	}

	
	//pending.erase(pending.begin()); // On passe le premier pendind devant le premier main car il est forcement + petit

	
	//ATTENTION PENDING [0] AU DEBUT DE MAIN ET DFIN DE PENDING
	main.insert(main.begin(), pending[0]); // insert the little of the first duo because we know it's smaller than all the main

	
	std::vector<IntPair> newPending = pendingManagement(pending);
	
	main = insert(main, newPending);
	std::vector<IntPair> final;
	for (long unsigned int i = 0; i < main.size(); i++){
		final.push_back(IntPair(main[i], i));
	}
	return (final);
}