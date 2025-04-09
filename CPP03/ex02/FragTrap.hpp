/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:51:43 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/08 11:10:42 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	FRAGTRAP_HPP
# define 	FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& copy);
	~FragTrap();
	
	void	highFivesGuys(void);

	protected:
	
};


#endif