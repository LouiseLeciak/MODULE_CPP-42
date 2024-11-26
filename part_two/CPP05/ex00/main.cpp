/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:42 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/13 11:05:19 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Dwight("Dwight", 5);


		std::cout << "\033[0;35mNO ERROR\033[0m\n" << std::endl;
		Dwight.decrementGrade();
		std::cout << Dwight;

		Dwight.decrementGrade();
		std::cout << Dwight;


		Dwight.incrementGrade();
		Dwight.incrementGrade();
		Dwight.incrementGrade();
		Dwight.incrementGrade();
		std::cout << Dwight;

		std::cout << "\033[0;35m\nWITH ERROR\033[0m\n" << std::endl;
		//Bureaucrat Jim("Jim", 167);
		//Bureaucrat Michael("Michael", 0);
		Bureaucrat Jim("Jim", 1);
		
		Jim.decrementGrade();
		
		
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}