/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:53:05 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 17:39:08 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cout << "invalid input." << std::endl, 1);
		
	std::ifstream	infile(argv[1]);
	std::string		copy;
	std::string		newFile = argv[1];
	std::string 	s1 = argv[2];
	std::string 	s2 = argv[3];
	
	if (s1.empty())
		return (0);
	newFile += ".replace";
	
	infile.is_open();
	while (infile.good())
		std::getline(infile, copy, '\0');
	infile.close();
	if (copy.empty())
		return (0);
	
	// find give the pos, npos represents the maximum possible value for an index in a string
	// start from 0 then from the last find
	for (unsigned long i = copy.find(s1, 0); i != std::string::npos; i = copy.find(s1, i))
	{
		copy.erase(i, s1.size());
		copy.insert(i, s2);
		i += s2.size();
	}
	std::ofstream outfile(newFile.c_str());

	// writes the copy to the outfile
	if (outfile.is_open())
		outfile << copy;
	return (1);
}