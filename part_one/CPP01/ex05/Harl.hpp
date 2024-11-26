/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:36:30 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/03 17:41:51 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class Harl
{
	public:
	
	Harl();
	~Harl();
	typedef void(Harl::*fptr)();
	void	complain(std::string level);
	fptr 	findByLevel(std::string level);

	
	private:
	
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		struct s_entry
		{
			std::string	level;
			fptr		fonction;
		};

		s_entry	_allLevels[4];

};


#endif