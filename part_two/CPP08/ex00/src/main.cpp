/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:48:38 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/19 08:20:28 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>

int main(void)
{
    try
    {
        std::vector<int>tab;     
        
        tab.push_back(1);
        tab.push_back(2);
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