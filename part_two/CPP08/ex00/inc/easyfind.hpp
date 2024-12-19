/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:18:17 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/19 07:53:45 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw(){return "Exception: occurence not found.";};
};

template<typename T>
typename T::iterator	easyfind(T &cont, int i){
    if (std::find(cont.begin(), cont.end(), i) == cont.end())
        throw(NotFoundException());
    std::cout << "found " << i << " in container." << std::endl;
    return(std::find(cont.begin(), cont.end(), i));
};

#endif