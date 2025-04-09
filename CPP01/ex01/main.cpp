/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:00:26 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 17:19:53 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int 	N = 15;
	Zombie *horde = zombieHorde(N, "Fred");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}