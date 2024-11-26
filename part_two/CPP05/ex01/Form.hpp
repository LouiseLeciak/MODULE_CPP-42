/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:59:32 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/13 14:49:00 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	FORM_HPP
# define 	FORM_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	
	Form(const std::string name, int signGrade, int execGrade);
	Form();
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	virtual ~Form();

	std::string	getName()const;
	int			getSignGrade()const;
	int			getExecGrade() const;
	bool		getSigned() const;

	void		beSigned(const Bureaucrat& tester);


		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		
};



#endif