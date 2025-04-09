/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:17:40 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/29 14:45:34 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CURE_HPP
# define 	CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public virtual AMateria
{
	public:

		Cure();
		Cure(const Cure& copy);
		const Cure& operator=(const Cure& copy);
		~Cure();

		Cure*	clone() const;
		void	use(ICharacter& target);
};


#endif