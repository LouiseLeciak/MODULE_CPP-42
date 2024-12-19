/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:23:18 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/19 13:11:21 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Span.hpp"

Span::Span(){};
Span::Span(unsigned int N): _N(N){};
Span::~Span(){};
// Span::Span(Span &copy){(*this) = copy;};
Span &Span::operator=(Span &copy){
    this->_N = copy._N;
	this->_tab = copy._tab;
	return (*this);
}

//////////////////////////////////////////////////

void    Span::addNumber(int nb){
    if (this->_tab.size() == this->_N)
        throw ContainerFullException();
    _tab.push_back(nb);
}

void    Span::addSeveralNumbers(iter first, iter last){
     if (std::distance(first, last) > this->_N)
		throw Span::ContainerFullException();
	else {
		this->_tab.insert(this->_tab.end(), first, last);
	}
}

unsigned int     Span::longestSpan()const{
    if (this->_tab.empty() || this->_tab.size() == 1)
        throw NoDistanceException();
    std::vector<int>sortedTab = this->_tab;
    std::sort(sortedTab.begin(), sortedTab.end());
   	return (sortedTab[sortedTab.size() - 1] - sortedTab[0]);
}

unsigned int     Span::shortestSpan()const{
    if (this->_tab.empty() || this->_tab.size() == 1)
        throw NoDistanceException();
    int	longestSpan = this->longestSpan();
	for(unsigned long i = 0; i < this->_tab.size(); i++)
	{
		for(unsigned long j = 0; j < this->_tab.size(); j++)
			if (longestSpan > (this->_tab[i] - this->_tab[j])
				&& (this->_tab[i] - this->_tab[j]) > 0)
				longestSpan = (this->_tab[i] - this->_tab[j]);
	}
	return (longestSpan);
}
