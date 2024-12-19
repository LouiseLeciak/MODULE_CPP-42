/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:48:38 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/19 13:19:23 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <iostream>

int main()
{   ////////main///////
    try
    {
        std::cout << "-----SUBJECT'S MAIN-----\n" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;    
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    ////////10000 nombres/////////
   try
    {
        std::cout << "\n-----10000 MAIN-----\n" << std::endl;
        Span sp = Span(10000);
        for (int i = 10000; i > 0; i--)
            sp.addNumber(rand()%100);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;    
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    /////////TOO SMALL CONTAINER///////
     try
    {
        std::cout << "\n-----CONTAINER WITH ONLY 1 INT-----\n" << std::endl;
        Span sp = Span(1);
        sp.addNumber(6);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;    
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    /////////////add several numbers//////////////
	try
	{
        std::cout << "\n-----ADD SEVERAL NMB-----\n" << std::endl;
		Span sp = Span(5);
		std::vector<int> toAdd;
		
		toAdd.push_back(6);
		toAdd.push_back(3);
		toAdd.push_back(17);
		toAdd.push_back(9);
		toAdd.push_back(11);

		sp.addSeveralNumbers(toAdd.begin(), toAdd.end());
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    /////////add too much numbers////////
    try
	{
        std::cout << "\n-----ADD TOO MUCH NMB-----\n" << std::endl;
		Span sp = Span(5);
		std::vector<int> toAdd;
		
		toAdd.push_back(6);
		toAdd.push_back(3);
		toAdd.push_back(17);
		toAdd.push_back(9);
		toAdd.push_back(11);
        toAdd.push_back(103);

		sp.addSeveralNumbers(toAdd.begin(), toAdd.end());
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan()  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
    return 0;
}
