/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 07:26:04 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/04 12:58:45 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	onlyDigit(std::string str)
{
	int i = -1;
	
	while (str[++i])
		if (!std::isdigit(str[i]))
			return (0);
	return (1);
}

int	main()
{
	Phonebook	initPhonebook;
	initPhonebook.runPhonebook();
	return (0);
}

