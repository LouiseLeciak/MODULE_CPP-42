/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:21:49 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/18 10:31:56 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void	iter(T *arr, int len, void (*f)(const T&))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
};


#endif