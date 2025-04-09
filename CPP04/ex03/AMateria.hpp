/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:05:13 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 12:29:51 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	AMATERIA_HPP
# define 	AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:

	std::string _type;
	
	public:

		AMateria();
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& copy);
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif