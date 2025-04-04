/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:23:01 by lleciak           #+#    #+#             */
/*   Updated: 2025/04/04 15:26:57 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"


// // inserer les pendings dans le main avec un binary search;
// std::vector<int> insert(std::vector<int> main, std::vector<IntPair> pending){
// 	for (int i = 0; i <= pending.size(); i++){
// 		int current = pending[i].value;// objet qu'on test, savoir ou on le met
// 		int j = pending[i].index / 2; // aller au milieu du tableau   	KOI SI TABLEAU = 1
// 		while (current < main[j - 1] || current > main[j]){
// 			if (current > main[j]) // euh pas sur mais un peu mieux que lautre
// 				j = (pending[i].index - j) / 2;
// 			else if (current < main[j])// euh pas sur
// 				j -= (j / 2);
// 		}
// 		//main.insert(j, current);
// 	}
// 	return (main);
// }


// // trier pending dans l'order jacob + index
// std::vector<IntPair> pendingManagement(std::vector<int> pending){
// 	std::vector<int> Jacobsthal;
// 	int j = 1;
// 	int prec = 1;
// 	for (int i = 0; j <= pending.size(); i++){
// 		int temp;
// 		Jacobsthal.push_back(j);
// 		temp = j;
// 		// j + precedent jacobcaca;
// 		// prec = j;
// 	}
// 	// apres ce for on a un vector remplis avec la suite de jacob dont on a besoin
// 	std::vector<IntPair> pendingFinal;
// 	int jacobPrecIt = 0;// precedent jacob
// 	int	jacobIt = 1;//iterator jacob
// 	int	comp = 0;
// 	for (int i = 1; i<pending.size(); i++){
// 		int index = Jacobsthal[jacobIt] - comp++;
// 		if (index <= Jacobsthal[jacobPrecIt]){ // si on arrive a 11, pour faire tt ceux qui manque 9,8,7,6,5..
// 			index = Jacobsthal[++jacobIt];
// 			comp = 0;	
// 		}
// 		pendingFinal.push_back(IntPair(pending[Jacobsthal[index]], index)); // pendingcopy c'est les pending range en combinaison de jacob + index
// 	}
// 	return (pendingFinal);
// }

// sort l'input selon l'algo de Ford Johnson
std::vector<IntPair> sort(std::vector<long unsigned int> input){
	if (input.size() <= 2){ //sort pour 2 
		std::vector<IntPair> pair;
		pair.push_back(IntPair(input[0], 0));
		pair.push_back(IntPair(input[1], 1));
		if (input[0] > input[1]){
			std::vector<IntPair> tmp;
			tmp.push_back(pair[1]);
			pair[1] = pair[0];
			pair[0] = tmp[0];
		}
		return (pair);
	}

	std::vector<int> main;
	std::vector<int> pending;
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
	
	//sort inside pairs
	for (long unsigned int i = 0; i < main.size(); i++){
		if (pending[i] > main[i]){
			std::vector<int> tmp;
			tmp.push_back(pending[i]);
			pending[i] = main[i];
			main[i] = tmp[0];
		}
	}
	
	// sorted = sort(main);
	// std::vector<int> copyPending = pending;
	// for(int i = 0; i <= main.size(); i++;){
	// 	main[i] = sorted[i].value;
	// 	pending[i] = copyPending[sorted[i].index]; // on reorganise pending comme on a organise main;
	// }
	// //pending.erase(pending[0]); // On passe le premier pendind devant le premier main car il est forcement + petit
	// //ATTENTION PENDING [0] AU DEBUT DE MAIN ET DFIN DE PENDING
	// main.pushdevant(pending[0]);
	// std::vector<IntPair> newPending = pendingManagement(pending);
	// main = insert(main, newPending);
	// std::vector<IntPair> final;
	// for (int i = 0; i < main.size(); i++){
	// 	final.push_back(IntPair(main[i], i));
	// }
	// return (final);
}