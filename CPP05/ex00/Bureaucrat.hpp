/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:59:32 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/07 14:52:08 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	BUREAUCRAT_HPP
# define 	BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <exception>

class Bureaucrat
{
	public:
	
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	virtual ~Bureaucrat();

	
	void	incrementGrade();
	void	decrementGrade();
	
	std::string	getName()const;
	int			getGrade()const;
	void		setGrade(int grade);
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:

		const std::string	_name;
		int					_grade;

		
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bur);

#endif