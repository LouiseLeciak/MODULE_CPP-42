/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:23:01 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/05 00:15:28 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <algorithm>


// inserer les pendings dans le main avec un binary search;
std::vector<IntPair> insert(std::vector<IntPair> main, std::vector<IntPair> pending){

	for (long unsigned int i = 0; i < pending.size(); i++){
		IntPair current = pending[i];// objet qu'on test, savoir ou on le met
		long unsigned int high = main.size(); // aller au milieu du tableau
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
		//main.insert(position, quoi);
		main.insert(main.begin() + mid, current);
	}
	return (main);
}


// trier pending dans l'order jacob + index
std::vector<IntPair> pendingManagement(std::vector<IntPair> pending){
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
		
		pendingFinal.push_back(IntPair(pending[index - 1].value, pending[index - 1].index)); // pendingcopy c'est les pending range en combinaison de jacob + index
	}
	return (pendingFinal);
}



// sort l'input selon l'algo de Ford Johnson
// on ne fait pas de copie, on trafic input directement => donc void
void sort(std::vector<IntPair>& input){
	if (input.size() == 2){ //sort pour 2 
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
	
	// ranger les main et les pending
	if (input.size() % 2 == 1){ // si un nombre impaire d'input donc un boloss
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
		if (pending[i].value > main[i].value){// sort IN PAIRS
			// std::vector<int> tmp;
			// tmp.push_back(pending[i]);
			int tmp = pending[i].value;
			pending[i].value = main[i].value;
			pending[i].index = input[i*2].index;// i * 2 parce que les pendings = 1 sur 2 dans la chaine principale d'input
			main[i].value = tmp;
		}
	}
	sort(main);
	
	// we organize pending like we did with main
	std::vector<IntPair> copyPending = pending;
	
		
	for(long unsigned int i = 0; i < main.size(); i++){
		pending[i] = copyPending[main[i].index];
	}

	// pour chaque main on va chercher dans input l'index original
	for(unsigned long int i = 0; i < main.size(); i ++)
	{
		for (unsigned long int j = 0; j<input.size(); j++)
		{
			if(input[j].value == main[i].value)
				main[i].index = input[j].index;
		}
	}
	
	//pending.erase(pending.begin()); // On passe le premier pendind devant le premier main car il est forcement + petit

	
	//ATTENTION PENDING [0] AU DEBUT DE MAIN ET DFIN DE PENDING
	main.insert(main.begin(), IntPair(pending[0])); // insert the little of the first duo because we know it's smaller than all the main

	
	std::vector<IntPair> newPending = pendingManagement(pending);

	main = insert(main, newPending);
	
	// on modifie input car c'est une reference
	for (long unsigned int i = 0; i < main.size(); i++)
		input[i]= main[i];
}