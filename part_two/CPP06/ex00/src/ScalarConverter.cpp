/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/20 13:57:18 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include "../inc/ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
// {
// 	(void)copy;
// }

ScalarConverter::~ScalarConverter(){};


///////////////////////utils//////////////////////////////////
void	print_pl(std::string literal)
{
	std::cout << "char: impossible value." << std::endl;
	std::cout << "int: impossible value." << std::endl;
	// atof => prend une string, l'interprete comme un float
	std::cout << "float: " << std::atof(literal.c_str()) << std::endl;
	// str to double
	std::cout << "double: " << static_cast<double>(std::strtod(literal.c_str(), NULL)) << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	char		c;
	float		float_nb;
	double		double_nb;
	bool		pt = 0;
	std::string	pseudo_lit[] = {"inf", "inff", "-inf", "-inff", "nan"};
	
	// on parse pour voir s'il s'agit d'un pseudo literal
	for (int i = 0; i < 5; i++){
		if (literal == pseudo_lit[i]){
			print_pl(literal);
			return;
		}
	}
	// CHAR
	// atoll = c string aka array to long long int
	if ((literal.size() == (size_t)1 && !std::isdigit(literal[0]))
	|| (std::isdigit(literal[0]) && std::atoll(literal.c_str()) < 128 && std::atoll(literal.c_str()) >= -128))
	{
		if (!std::isdigit(literal[0]))
			c = static_cast<char>(literal[0]);
		else	
			c = static_cast<char>(std::atoi(literal.c_str()));

		//check if c is a printable character
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: non printable char" << std::endl;
			
		std::cout << "int: " << static_cast<int>(c) << std::endl;

		if (!std::isdigit(literal[0]))
		{
			std::cout << "float: " << static_cast<float>(c) << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
		}
		else
		{
			std::cout << "float: " << std::atof(literal.c_str()) << std::endl;
			std::cout << "double: " << std::strtod(literal.c_str(), NULL) << std::endl;
		}
	}

	// DOUBLE FLOAT
	else
	{
		for (size_t i = 0; i < literal.size() - 1; i++){
			if (!std::isdigit(literal[i]) && ((literal[i] == '.' && pt) || literal[i] != '.'))
			{
				std::cout << "Impossible value."<< std::endl;
				return;
			}
			else if ((size_t)i == literal.size() - 2)
			{
				double_nb = std::strtod(literal.c_str(), NULL);
				float_nb= static_cast<float>(double_nb);

				if (static_cast<int>(float_nb) < 128 && static_cast<int>(float_nb) >= -127)
					std::cout << "char: '" << static_cast<char>(float_nb) << "'" << std::endl;
				else
					std::cout << "char: impossible value" << std::endl;

				if(std::atoll(literal.c_str()) > 2147483647 
				|| std::atoll(literal.c_str()) < -((long long)2147483647 - 1))
					std::cout << "int: impossible value" << std::endl;
				else
					std::cout << "int: " << std::atoi(literal.c_str()) << std::endl;

				std::cout << "float: " << float_nb << std::endl;
				std::cout << "double: " << double_nb << std::endl;
			}
			if (literal[i] == '.')
				pt = true;
		}
		return;
	}
}
