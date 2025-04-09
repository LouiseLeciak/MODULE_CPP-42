/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 07:47:11 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 16:13:15 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

int	onlyDigit(std::string str);

class Phonebook
{
	public:
	
	int		runPhonebook(void);
	
	private:
	
		int		addContact(void);
		int		displayShort(void);
		int		displayFull(void);
		Contact _contacts[8];
};

# endif