/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:48:38 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/21 08:15:21 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
    std::cout << "*** VECTOR ***\n" << std::endl;
    try
    {
        std::vector<int>tab;     
        
        tab.push_back(1);
        tab.push_back(7);
        tab.push_back(42);
        tab.push_back(3);
        easyfind(tab, 42);
        easyfind(tab, 9);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\n\n*** LIST ***\n" << std::endl;
    try
    {
        std::list<int>tab;     
        
        tab.push_back(1);
        tab.push_back(7);
        tab.push_back(42);
        tab.push_back(3);
        easyfind(tab, 42);
        easyfind(tab, 9);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}