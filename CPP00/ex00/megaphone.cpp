/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:19:07 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 16:43:52 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
	else if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
			if (argv[i + 1])
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (1);
}