/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:48:38 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/20 09:06:21 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

#include <list>
#include <vector>

int main()
{
	std::cout << "-----MutantStack-----" << std::endl;
	try
	{
		MutantStack<int> mutant;
	
		mutant.push(1);
		mutant.push(2);
        
        std::cout << "size:" << std::endl;
		std::cout << mutant.size() << std::endl;
		
        std::cout << "access first element:" << std::endl;
		std::cout << mutant.top() << std::endl;

        std::cout << "removes top element & access first" << std::endl;
        mutant.pop();
		std::cout << mutant.top() << std::endl;

		
        std::cout << "size:" << std::endl;
		std::cout << mutant.size() << std::endl;
		
		mutant.push(3);
		mutant.push(4);
		mutant.push(5);
		
        std::cout << "# iterator remaining #" << std::endl;
		MutantStack<int>::iterator itb = mutant.begin();
		MutantStack<int>::iterator ite = mutant.end();
		
		++itb;
		--itb;
		while (itb != ite)
		{
			std::cout << *itb << std::endl;
			++itb;
		}
		std::stack<int> stck(mutant);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-----Vector-----\n" << std::endl;
	try
	{
		std::vector<int> mutant;
	
		mutant.push_back(1);
		mutant.push_back(2);
        
        std::cout << "size:" << std::endl;
		std::cout << mutant.size() << std::endl;
		
        std::cout << "access first element:" << std::endl;
		std::cout << mutant.back() << std::endl;

        std::cout << "removes top element & access first" << std::endl;
        mutant.pop_back();
		std::cout << mutant.back() << std::endl;

		
        std::cout << "size:" << std::endl;
		std::cout << mutant.size() << std::endl;
		
		mutant.push_back(3);
		mutant.push_back(4);
		mutant.push_back(5);
		
        std::cout << "# iterator remaining #" << std::endl;
		std::vector<int>::iterator itb = mutant.begin();
		std::vector<int>::iterator ite = mutant.end();
		
		++itb;
		--itb;
		while (itb != ite)
		{
			std::cout << *itb << std::endl;
			++itb;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}