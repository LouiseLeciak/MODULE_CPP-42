/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:32:53 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/20 08:47:13 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack(){};
        MutantStack(MutantStack& copy){*this = copy;};
        ~MutantStack(){};
        MutantStack& operator=(MutantStack& copy)
		{
			*this = copy;
			return (*this);
		};
        typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void){return this->c.begin();}
	iterator end(void){return this->c.end();}
        
};

#endif