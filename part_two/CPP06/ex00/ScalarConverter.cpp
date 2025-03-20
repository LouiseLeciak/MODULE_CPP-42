/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:41 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/14 16:54:04 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

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
	std::string	pseudo_lit[] = {"+inf", "+inff", "-inf", "-inff", "nan", "nanf", "eot"};
	int	i = 0;
	
	while (pseudo_lit[i] != "eot"){
		if (literal == pseudo_lit[i])
			return (i + 200);
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

	if (parser.size() > 2){
		return (-1);
	}
	else if (parser.size() == 1){
		if (parser[0].size() == 3 && literal[0] == '\'' && literal[2] == '\''){
			return (CHAR);}
		while (parser[0][i] && isAChar == 0){
			if (parser[0][i] < 48 || parser[0][i] > 57){
				std::cout << "Not a numeric input" << std::endl;
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
		i = 0;
		if (negative == 1){
			i++;
		}
		while (parser[0][i]){
			if (parser[0][i] < 48 || parser[0][i] > 57){
				return (-1);
			}
			i++;
		}
		i = 0;
		int j = parser[1].size();
		while (parser[1][i]){
			if (i == j - 2){
				i++;
				break;
			}
			if (parser[1][i] < 48 || parser[0][i] > 57){
				std::cout << "Not a numeric input" << std::endl;
				return (-1);
			}
			i++;
		}
		if (parser[1][i] == 'f' || parser[1][i] == 'F' || (parser[1].size() == 1 && (parser[1][0] == 'f' || parser[1][0] == 'F')))
			return (FLOAT);
		else if (parser[1][i] > 48 || parser[0][i] < 57)
			return (DOUBLE);
		else 
			return (-1);
	}
	return (-1);
}


///////////////////////////////////////////////convertion and cast/////////////////////////////

void	charLit(std::string input)
{
	char	c;
	c = input[1];

	std::cout << "INPUT = CHAR\n" << std::endl; 
	
	std::cout << "INT:     " << static_cast<int>(c) << std::endl;
	
	if (static_cast<double>(c) < 0 || static_cast<double>(c) > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (c < 32 || c > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << c << "\'" << std::endl;
		
	std::cout.setf(std::ios::fixed);
	if (c < -std::numeric_limits<float>::max() || c > std::numeric_limits<float>::max())
		std::cout << "FLOAT:   " << "impossible." << std::endl;
	else
		std::cout << "FLOAT:   " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "DOUBLE:  " << static_cast<double>(c) << std::endl;
}

void	intLit(std::string input)
{
	long int	i;

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
	//std::cout.setf(std::ios::fixed);
	if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max())
		std::cout << "FLOAT:   " << "impossible." << std::endl;
	else
		std::cout << "FLOAT:   " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "DOUBLE:  " << static_cast<double>(i) << std::endl;

}

void	floatLit(std::string input)
{
	float	f;

	f = atof(input.c_str());
	std::cout << "INPUT = FLOAT\n" << std::endl; 

	if (f < -2147483648.f || f > 2147483647.f)
		std::cout << "INT:     " << "impossible." << std::endl;
	else
		std::cout << "INT:     " << static_cast<int>(f) << std::endl;
	
	if (f < 0 || f > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (f < 32 || f > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << static_cast<char>(f) << "\'" << std::endl;

	//std::cout.setf(std::ios::fixed);
	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "FLOAT:   " << "impossible." << std::endl;
	else
		std::cout << "FLOAT:   " << f << "f" << std::endl;
	
	std::cout << "DOUBLE:  " << static_cast<double>(f) << std::endl;
}

void	doubleLit(std::string input)
{
	double	d;

	std::cout << "INPUT = DOUBLE\n" << std::endl; 

	d = atof(input.c_str());

	if (d < -2147483648 || d > 2147483647)
		std::cout << "INT:     " << "impossible." << std::endl;
	else
		std::cout << "INT:     " << static_cast<int>(d) << std::endl;
	
	if (d < 0 || d > 255)
		std::cout << "CHAR:    " << "impossible." << std::endl;
	else if (d < 32 || d > 126)	
		std::cout << "CHAR:    " << "non displayable character." << std::endl;
	else
		std::cout << "CHAR:    " << "\'" << static_cast<char>(d) << "\'" << std::endl;
		
	//std::cout.setf(std::ios::fixed);
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "FLOAT:   " << "impossible." << std::endl;
	else
		std::cout << "FLOAT:   " << static_cast<float>(d) << "f"<< std::endl;
	std::cout << "DOUBLE:  " << d << std::endl;
}

void		pseudoLit(std::string literal, int p)
{
	if (p == INF)
	{
		std::cout << "INT:     " << "impossible." << std::endl;
		std::cout << "CHAR:    " << "impossible." << std::endl;
		std::cout << "FLOAT:   " << literal << "f" << std::endl;
		std::cout << "DOUBLE:  " << literal << std::endl;
	}
	if (p == INFF)
	{
		std::cout << "INT:     " << "impossible." << std::endl;
		std::cout << "CHAR:    " << "impossible." << std::endl;
		std::cout << "FLOAT:   " << literal << std::endl;
		std::cout << "DOUBLE:  " << "+inf" << std::endl;
	}
	if (p == MINF)
	{
		std::cout << "INT:     " << "impossible." << std::endl;
		std::cout << "CHAR:    " << "impossible." << std::endl;
		std::cout << "FLOAT:   " << literal << "f" << std::endl;
		std::cout << "DOUBLE:  " << literal << std::endl;
	}
	if (p == MINFF)
	{
		std::cout << "INT:     " << "impossible." << std::endl;
		std::cout << "CHAR:    " << "impossible." << std::endl;
		std::cout << "FLOAT:   " << literal << std::endl;
		std::cout << "DOUBLE:  " << "-inf" << std::endl;
	}
	if (p == NAN)
	{
		std::cout << "INT:     " << "impossible." << std::endl;
		std::cout << "CHAR:    " << "impossible." << std::endl;
		std::cout << "FLOAT:   " << literal << "f" << std::endl;
		std::cout << "DOUBLE:  " << literal << std::endl;
	}
	if (p == NANF)
	{
		std::cout << "INT:     " << "impossible." << std::endl;
		std::cout << "CHAR:    " << "impossible." << std::endl;
		std::cout << "FLOAT:   " << literal << std::endl;
		std::cout << "DOUBLE:  " << "nan" << std::endl;
	}
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
		pseudoLit(literal, isAPseudoLit);
	else if (lit > 0)
	{
		if (lit == CHAR)
			charLit(literal);
		if (lit == INT)
			intLit(literal);
		if (lit == FLOAT)
			floatLit(literal);
		if (lit == DOUBLE)
			doubleLit(literal);
	}
	
	return (0);
}

	
		
