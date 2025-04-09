/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:11:08 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 12:08:44 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	ICE_HPP
# define 	ICE_HPP

#include "AMateria.hpp"

class Ice : public virtual AMateria
{
	public:

		Ice();
		Ice(const Ice& copy);
		const Ice& operator=(const Ice& copy);
		~Ice();

		Ice* clone() const;
		void use(ICharacter& target);
};


#endif