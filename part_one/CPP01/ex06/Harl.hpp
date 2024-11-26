/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:36:30 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/01 11:00:07 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

enum LOGLEVEL // NONE =0, DBUG = 1 etc..
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

class Harl
{
	public:
	
	Harl();
	~Harl();
	typedef void(Harl::*fptr)();
	void	complain(std::string level);
	void 	newComplain(std::string loglevel);
	fptr 	findByLevel(std::string level);

	
	private:
	
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	struct entry
	{
		std::string	level;
		fptr		fonction;
	};

	entry	allLevels[4];

};


#endif