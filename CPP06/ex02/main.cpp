/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:50:17 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/19 13:56:53 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(int ac, char *av[])
{
	if (ac != 1)
		return(-1);
	(void)av;
	identify(generate());
	identify(*generate());
	return (0);
}