/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/14 15:17:36 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
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


std::vector<std::string> splitString(std::string str, char sep){

    std::stringstream split(str);
    std::string segment;
    std::vector<std::string> commands;
    while (std::getline(split, segment, sep)){
        commands.push_back(segment);
    }
    return (commands);
}

/////////////////////////////////parsing//////////////////////////

int	pseudoLitCheck(std::string literal){
	std::string	pseudo_lit[] = {"inf", "inff", "-inf", "-inff", "nan", "nanf", "eot"};
	int	i = 0;
	
	while (pseudo_lit[i] != "eot"){
		if (literal == pseudo_lit[i])
			return (i);
		i++;
	}
	return(-1);
}

int parseLiteral(std::string literal, const std::vector<std::string> parser){
	
	bool		isAChar = 0;
	bool		negative = 0;
	int			i = 0;
	
	if (literal[0] == '-'){
		negative = 1;
		i++;
	}

	if (parser.size() > 2){ // si plusieurs . mauvais input
		return (-1);
	}
	else if (parser.size() == 1){ // si pas de .
		if (parser[0].size() == 3 && literal[0] == '\'' && literal[2] == '\''){ // si 3 de len et entre ' ' 
			return (CHAR);}
		while (parser[0][i] && isAChar == 0){ // on se balade dans la string voir si il n'y a bien que des num
			if (parser[0][i] < 48 || parser[0][i] > 57){
				std::cerr << "Not a numeric input" << std::endl;
				return (-1);
			}
			i++;
		}
		if (isAChar == 0)
		{
			double a = atof(literal.c_str());

			if (a < -2147483648 || a > 2147483647)
				return DOUBLE;;
			return INT;
		}
	}
	else if (parser.size() == 2){
		i = 0; // si 2 parties, on verifie que les 2 sont clean, si oui on check s'il y a un f a la fin
		if (negative == 1){
			i++;
		}
		while (parser[0][i]){
			if (parser[0][i] < 48 || parser[0][i] > 57){
				return (-1);
			}
			i++;
		} // premiere partie clean
		i = 0;
		int j = parser[1].size();
		while (parser[1][i]){
			if (i == j - 2){
				i++;
				break;
			}
			if (parser[1][i] < 48 || parser[0][i] > 57){
				std::cerr << "Not a numeric input" << std::endl;
				return (-1);
			}
			i++;
		} // clean, on regarde le dernier character
		if (parser[1][i] == 'f' || parser[1][i] == 'F')
			return (FLOAT);
		else if (parser[1][i] > 48 || parser[0][i] < 57)
			return (DOUBLE);
		else 
			return (-1);
	}
	return (-1);
}


///////////////////////////////////////////////convertion and cast/////////////////////////////

void	charLit(std::string input, int fp_size)
{
	char	c;
	(void)fp_size;
	c = input[1];

	std::cout << "INPUT = CHAR\n" << std::endl; 
	
	std::cout << "INT:     " << static_cast<int>(c) << std::endl;
	if (static_cast<double>(c) < 0 || static_cast<double>(c) > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (c < 32 || c > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << c << "\'" << std::endl;
	std::cout.setf(std::ios::fixed);// flag for the 0.0f state
	
	std::cout << "FLOAT:   " << std::setprecision(7) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "DOUBLE:  " << std::setprecision(15) << static_cast<double>(c) << std::endl;
}

void	intLit(std::string input, int fp_size)
{
	long int	i;
	(void)fp_size;

	i = atof(input.c_str());
	std::cout << "INPUT = INT\n" << std::endl; 

	if (i < -2147483648 || i > 2147483647)
		std::cout << "INT:     " << "impossible." << std::endl;
	else
		std::cout << "INT:     " << i << std::endl;
		
	if (i < 0 || i > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (i < 32 || i > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << static_cast<char>(i) << "\'" << std::endl;
		
	std::cout.setf(std::ios::fixed);// flag for the 0.0f state
	
	if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max())
		std::cout << "FLOAT:   " << "impossible." << std::endl;
	else
		std::cout << "FLOAT:   " << std::setprecision(7) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "DOUBLE:  " << std::setprecision(15) << static_cast<double>(i) << std::endl;

}

void	floatLit(std::string input, int fp_size)
{
	float	f;
	int		p;

	f = atof(input.c_str());
	std::cout << "INPUT = FLOAT\n" << std::endl; 


	std::cout << "INT:     " << static_cast<int>(f) << std::endl;
	if (f < 0 || f > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (f < 32 || f > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << static_cast<char>(f) << "\'" << std::endl;
	std::cout.setf(std::ios::fixed);// flag for the 0.0f state
	
	p = 7 - fp_size;
	if (p < 0)
		std::cout << "FLOAT:   " << static_cast<float>(f) << "f" << std::endl;
	else
		std::cout << "FLOAT:   " << std::setprecision(p) << static_cast<float>(f) << "f" << std::endl;

	p = 15 - fp_size;
	if (p < 0)	
		std::cout << "DOUBLE:  " << static_cast<double>(f) << std::endl;
	else
		std::cout << "DOUBLE:  " << std::setprecision(p) << static_cast<double>(f) << std::endl;
}

void	doubleLit(std::string input, int fp_size)
{
	double	d;
	(void)fp_size;

	std::cout << "INPUT = DOUBLE\n" << std::endl; 

	d = atof(input.c_str());
	
	std::cout << "INT:     " << static_cast<int>(d) << std::endl;
	if (d < 0 || d > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (d < 32 || d > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << static_cast<char>(d) << "\'" << std::endl;
	std::cout.setf(std::ios::fixed);// flag for the 0.0f state
	std::cout << "FLOAT:   " << std::setprecision(7) << static_cast<float>(d) << "f"<< std::endl;
	std::cout << "DOUBLE:  " << std::setprecision(15) << d << std::endl;
}

int ScalarConverter::convert(std::string literal)
{
	int			isAPseudoLit = -1;
	int			lit = 0;
	const std::vector<std::string> parser = splitString(literal, '.');
	
	if (pseudoLitCheck(literal) > -1)
		isAPseudoLit = pseudoLitCheck(literal);
	else
		lit = parseLiteral(literal, parser);

	if (isAPseudoLit > -1)
		std::cout<<"pseudo-lit"<<std::endl;
	else if (lit > 0)
	{
		if (lit == CHAR)
			charLit(literal, parser[0].size());
		if (lit == INT)
			intLit(literal, parser[0].size());
		if (lit == FLOAT)
			floatLit(literal, parser[0].size());
		if (lit == DOUBLE)
			doubleLit(literal, parser[0].size());
	}
	
	return (0);
}

	
		
