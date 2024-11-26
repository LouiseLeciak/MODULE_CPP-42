/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:42 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/13 14:08:29 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	Dwight("Dwight", 5);
		Bureaucrat	Michael("Michael", 1);
		
		Form		Document("Document", 10, 10);
		Form		BossDoc("Boss's document", 1, 1);

		Dwight.signForm(Document);
		Dwight.signForm(BossDoc);
		
		Michael.signForm(Document);
		Michael.signForm(BossDoc);
		
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}