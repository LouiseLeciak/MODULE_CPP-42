/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:42 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/22 17:00:35 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	try
	{
		Bureaucrat	Michael("Michael", 1);
		Intern Bill;
		AForm* homemadeForm;

		homemadeForm = Bill.makeForm("shrubbery creation", "tree");
		if (!homemadeForm)
		{
			std::cout << "Intern could not create form." << std::endl;
			return (1);
		}
		Michael.signForm(*homemadeForm);
		Michael.executeForm(*homemadeForm);
			
		std::cout << "\n\n";	
		
		homemadeForm = Bill.makeForm("robotomy request", "random robot");
		if (!homemadeForm)
		{
			std::cout << "Intern could not create form." << std::endl;
			return (1);
		}
		Michael.signForm(*homemadeForm);
		Michael.executeForm(*homemadeForm);

		std::cout << "\n\n";	
		
		homemadeForm = Bill.makeForm("presidential pardon", "bibo");
		if (!homemadeForm)
		{
			std::cout << "Intern could not create form." << std::endl;
			return (1);
		}
		Michael.signForm(*homemadeForm);
		Michael.executeForm(*homemadeForm);
		
		std::cout << "\n\n";	
		
		homemadeForm = Bill.makeForm("dance form", "dancing queen");
		if (!homemadeForm)
		{
			std::cout << "Intern could not create form." << std::endl;
			return (1);
		}
		Michael.signForm(*homemadeForm);
		Michael.executeForm(*homemadeForm);


	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}