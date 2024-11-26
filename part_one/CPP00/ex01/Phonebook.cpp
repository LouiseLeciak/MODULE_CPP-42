/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:48:21 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/07 13:10:46 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	Phonebook::displayShort(void)
{
	std::string name;
	std::string lname;
	std::string kname;
	
	int	i = 0;

	while (i < 8)
	{

		name = this->_contacts[i].getFirstName();
		lname = this->_contacts[i].getLastName();
		kname = this->_contacts[i].getNickName();

		if (name.size() > 10)
			name = name.substr(0, 9) + ".";
		if (lname.size() > 10)
			lname = lname.substr(0, 9) + ".";
		if (kname.size() > 10)
			kname = kname.substr(0, 9) + ".";
		
		std::cout << std::setw(10) << "[" << i << "] |";
		std::cout << std::setw(10) << name;
		std::cout << "|";
		std::cout << std::setw(10) << lname;
		std::cout << "|";
		std::cout << std::setw(10) << kname << std::endl;
		i++;
	}
	if (displayFull() == 1)
		return (1);
	return (0);
}

int	Phonebook::displayFull(void)
{
    std::string    input;

    std::cout << "please select a contact number : ";
    std::cin >> input;
    std::cin.ignore();
    
    if (std::atoi(input.c_str()) > 7 || std::atoi(input.c_str()) < 0 || !onlyDigit(input))
	{
        std::cout << "Input unavailable." << std::endl;
        return (1);
    }
    
    std::cout << "Name: " << this->_contacts[std::atoi(input.c_str())].getFirstName() << std::endl;
    std::cout << "Last name: " << this->_contacts[std::atoi(input.c_str())].getLastName() << std::endl;
    std::cout << "Nickname: " << this->_contacts[std::atoi(input.c_str())].getNickName() << std::endl;
    std::cout << "Phone number: " << this->_contacts[std::atoi(input.c_str())].getNumber() << std::endl;
    std::cout << "Darkest secret: " << this->_contacts[std::atoi(input.c_str())].getSecret() << std::endl;
    
    return (0);
}

int	Phonebook::addContact(void)
{
	static int index = 0;

	this->_contacts[index % 8].initContact();
	index++;
	return (0);
}

int	Phonebook::runPhonebook(void)
{
	std::string	action;

	while (action != "EXIT")
	{
		std::cout << "\033[0;35mWelcome, please make a choice:\033[0m" << std::endl;
		std::cout << "\033[0;35mADD -> Add a new contact\033[0m" << std::endl;
		std::cout << "\033[0;35mSEARCH -> display the contact\033[0m" << std::endl;
		std::cout << "\033[0;35mEXIT -> exit the phonebook\033[0m" << std::endl;
		
		std::getline(std::cin, action);
		if (std::cin.eof())
			break;
		if (action == "ADD")
			addContact();
		else if (action == "SEARCH")
			if (displayShort() == 1)
				continue ;	
	}
	return (0);
}
