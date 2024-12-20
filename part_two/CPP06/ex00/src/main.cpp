/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:48:22 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/20 13:49:21 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
		return (1);
	ScalarConverter::convert(av[1]);
	return (0);
}