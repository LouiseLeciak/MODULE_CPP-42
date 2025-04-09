/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:21:49 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/18 09:35:57 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b)
{
	T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T& a, T& b)
{
	if (a > b || a == b)
		return b;
	return a;
}

template<typename T>
T max(T& a, T& b)
{
	if (a < b || a == b)
		return b;
	return a;
}

#endif