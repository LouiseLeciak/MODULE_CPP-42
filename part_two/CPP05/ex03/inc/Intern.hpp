/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:09:47 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/22 16:47:13 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		const Intern& operator=(const Intern& copy);
		~Intern();
		
		typedef	AForm*(Intern::*fptr)(std::string target);
		AForm	*createShrubbery(const std::string target);
		AForm	*createRobotomy(const std::string target);
		AForm	*createPresident(const std::string target);

		AForm *makeForm(std::string name, std::string target);
		fptr	whatForm(std::string name);
		

	private:
		struct s_entry
		{
			std::string	form;
			fptr		fonction;
		};

		s_entry	_allForms[3];
};

#endif