/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:13:41 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 15:04:00 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CHARACTER_HPP
# define 	CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{	
	public:

	Character();
	Character(std::string const & type);
	Character(const Character& copy);
	Character& operator=(const Character& copy);
	~Character();

	std::string const & getName() const;
	void 		equip(AMateria* m);
	void 		unequip(int idx);
	void 		use(int idx, ICharacter& target);

	protected:

		std::string	_name;
		AMateria*	_items[4];
};


#endif