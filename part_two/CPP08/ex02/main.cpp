/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:48:38 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/21 09:06:49 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>
#include <vector>

int main()
{
	std::cout << "-----Subject's main-----" << std::endl;
	try
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-----Subject's main with list-----" << std::endl;
	try
	{
		std::list<int> lst;
		
		lst.push_back(5);
		lst.push_back(17);
		
		std::cout << lst.back() << std::endl;

		lst.pop_back();

		std::cout << lst.size() << std::endl;
		
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-----MutantStack-----" << std::endl;
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
	std::cout << "\n-----List-----\n" << std::endl;
	try
	{
		std::list<int> mutant;
	
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
		std::list<int>::iterator itb = mutant.begin();
		std::list<int>::iterator ite = mutant.end();
		
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