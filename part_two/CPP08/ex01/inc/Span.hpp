/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:22:53 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/19 12:33:44 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
    private:
        unsigned int _N;
        typedef std::vector<int>::iterator iter;
        std::vector<int> _tab;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        //Span(Span &copy);
        Span &operator=(Span &copy);

        void            addNumber(int nb);
		void	        addSeveralNumbers(iter first, iter last);
        unsigned int    shortestSpan()const;
        unsigned int    longestSpan()const;

        
        class ContainerFullException: public std::exception{
            public: virtual const char* what() const throw(){return("Exception: container full.");}
        };

        class NoDistanceException: public std::exception{
            public: virtual const char* what() const throw(){return("Exception: No distance possible.");}
        };
    
        
};

#endif