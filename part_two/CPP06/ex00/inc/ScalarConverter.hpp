/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:22:22 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/13 13:40:57 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

#define CHAR 101
#define INT 102
#define FLOAT 103
#define DOUBLE 104

class ScalarConverter
{
	public:
		~ScalarConverter();
		static int convert(std::string literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
};

#endif