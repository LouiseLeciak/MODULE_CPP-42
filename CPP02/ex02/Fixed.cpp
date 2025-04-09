/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:50:23 by lleciak           #+#    #+#             */
/*   Updated: 2024/10/21 11:09:34 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return;
}

Fixed::Fixed(const Fixed& copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	(*this) = copy;
}

Fixed::Fixed(const int nb)// int to fixed
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = (nb << this->_bits);// << car on decale les bits de 8 
}


Fixed::Fixed(const float nb)//float to fixed
{
	//std::cout << "Float Constructor called." <<std::endl;
	this->_value = roundf(nb * (1 << this->_bits));
	//float * (1 << 8)
}


Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member called." << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member called." << std::endl;
	this->_value = raw;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	//std::cout << "Copy assignement operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

float 	Fixed::toFloat(void)const// fixed to float
{
	return((float)this->_value / (1 << this->_bits));
	// inverse du calcul de fload to fixed
	// cast float sinon chiffre rond
}

int 	Fixed::toInt(void)const // fixed to int
{
	return((int)this->_value / (1 << this->_bits));
	// inverse du calcul de int to fixed
}

std::ostream& operator<<(std::ostream& output, const Fixed& nb)
{
	output << nb.toFloat();
	return (output);
}


////////////////////////
//COMPARISON OPERATORS//
////////////////////////

bool Fixed::operator>(const Fixed& copy)
{
	if (this->toFloat() > copy.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& copy)
{
	if (this->toFloat() < copy.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& copy)
{
	if (this->toFloat() >= copy.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& copy)
{
	if (this->toFloat() <= copy.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& copy)
{
	if (this->toFloat() == copy.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& copy)
{
	if (this->toFloat() != copy.toFloat())
		return (true);
	return (false);
}


////////////////////////
//ARITHMETIC OPERATORS//
////////////////////////


float Fixed::operator+(const Fixed& copy)
{
	return (this->toFloat() + copy.toFloat());
}

float Fixed::operator-(const Fixed& copy)
{
	return (this->toFloat() - copy.toFloat());
}

float Fixed::operator*(const Fixed& copy)
{
	return (this->toFloat() * copy.toFloat());
}

float Fixed::operator/(const Fixed& copy)
{
	return (this->toFloat() / copy.toFloat());
}


/////////////////////////
//INCREMENT - DECREMENT//
/////////////////////////

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_value;
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_value;
	return (temp);
}


/////////////
//MIN - MAX//
/////////////

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}