/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:42 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 18:04:03 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat	Dwight("Dwight", 50);
		Bureaucrat	Michael("Michael", 1);
		
		
		ShrubberyCreationForm	formShrub("tree");
		RobotomyRequestForm		formRobot("R2D2");
		RobotomyRequestForm		formRobot2("Flocon");
		PresidentialPardonForm	formPresident("Mick");

		Michael.signForm(formShrub);
		Michael.executeForm(formShrub);

		std::cout << "\n----------------------------- \n" << std::endl;

		Michael.executeForm(formRobot);
		Dwight.signForm(formRobot);
		Dwight.signForm(formRobot2);

		Michael.executeForm(formRobot);
		Michael.executeForm(formRobot2);

		std::cout << "\n----------------------------- \n" << std::endl;

		Dwight.signForm(formPresident);
		Dwight.executeForm(formPresident);
		Michael.signForm(formPresident);
		Dwight.executeForm(formPresident);
		Michael.executeForm(formPresident);
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}