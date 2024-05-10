/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:16:28 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/10 23:54:12 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value)
{
	this->_value =  (float) roundf(value * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& copy) : _value(copy._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = copy.getRawBits();
	std::cout << "Assignation operator called "<< copy.toFloat() << std::endl;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat() const
{
	return(_value /(float)(1 << _fractionalBits));
}

int Fixed::toInt() const
{
	return(_value >> _fractionalBits);
	// return(2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}