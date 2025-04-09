/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:48:58 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/30 12:12:20 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	MATERIASOURCE_HPP
# define 	MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
	
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		const MateriaSource& operator=(const MateriaSource& copy);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
	
	protected:

		AMateria* _source[4];
};


#endif