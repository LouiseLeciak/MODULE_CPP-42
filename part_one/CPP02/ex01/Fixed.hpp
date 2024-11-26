/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:36:30 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/08 15:11:19 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed& operator=(const Fixed& copy);
	~Fixed();
	
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
	
	private:

	int					_value;
	static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream& output, const Fixed& nb);

#endif