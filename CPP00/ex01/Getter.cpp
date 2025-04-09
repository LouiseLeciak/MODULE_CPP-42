/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Getter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:58:02 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/03 11:42:27 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

std::string	Contact::getFirstName(void)
{
	return (_firstName);
}

std::string	Contact::getLastName(void)
{
	return (_lastName);
}

std::string	Contact::getNickName(void)
{
	return (_nickname);
}

std::string	Contact::getSecret(void)
{
	return (_darkestSecret);
}

std::string	Contact::getNumber(void)
{
	return (_phoneNumber);
}