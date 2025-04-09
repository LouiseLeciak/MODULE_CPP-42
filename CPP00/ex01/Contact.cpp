/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:33:04 by lleciak           #+#    #+#             */
/*   Updated: 2024/11/20 11:23:06 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::initContact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
	if (std::cin.eof())
		return(0);
	while (this->_firstName.length() < 1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, this->_firstName);
		if (std::cin.eof())
		return(0);
	}

	while (this->_lastName.length() < 1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, this->_lastName);
		if (std::cin.eof())
		return(0);
	}

	while (this->_nickname.length() < 1)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, this->_nickname);
		if (std::cin.eof())
		return(0);
	}

	while (this->_phoneNumber.length() < 1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, this->_phoneNumber);
		if (!onlyDigit(_phoneNumber))
			_phoneNumber = "n";
		if (std::cin.eof())
		return(0);
	}

	while (this->_darkestSecret.length() < 1)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, this->_darkestSecret);
		if (std::cin.eof())
		return(0);
	}
	return (0);
}
