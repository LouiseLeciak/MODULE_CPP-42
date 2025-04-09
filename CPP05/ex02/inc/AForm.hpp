/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:59:32 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/18 14:46:26 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	AFORM_HPP
# define 	AFORM_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	
	AForm(const AForm& copy);
	AForm& operator=(const AForm& copy);
	virtual ~AForm();

	std::string	getName()const;
	int			getSignGrade()const;
	int			getExecGrade() const;
	bool		getSigned() const;

	void			beSigned(const Bureaucrat& tester);
	virtual void	execute(Bureaucrat const & executor) const = 0;


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
		
		class isSignedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
	
	protected:

	AForm(const std::string name, int signGrade, int execGrade);
	AForm();
	
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		
};



#endif