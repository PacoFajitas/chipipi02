/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:16:28 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/11 01:47:30 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
	this->_value =  (float) roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed (const Fixed& copy) : _value(copy._value)
{
}

Fixed::~Fixed()
{
}


Fixed& Fixed::operator=(const Fixed &copy)
{
	_value = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
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

// Operators ++a --a y a++ a--
Fixed& Fixed::operator++()
{
	this->_value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->operator++();
	return (old);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	this->operator--();
	return (old);
}

// Arithmetic operators (+ - * /)

Fixed Fixed::operator+(Fixed add)
{
	return(this->toFloat() + add.toFloat());
}

Fixed Fixed::operator-(Fixed less)
{
	return(this->toFloat() - less.toFloat());
}

Fixed Fixed::operator*(Fixed por)
{
	return(this->toFloat() * por.toFloat());
}

Fixed Fixed::operator/(Fixed entre)
{
	return(this->toFloat()/entre.toFloat());
}

//Comparison operators

bool Fixed::operator<(Fixed& compa)
{
	return(this->toFloat() < compa.toFloat());
}

bool Fixed::operator<=(Fixed& compa)
{
	return(this->toFloat() <= compa.toFloat());
}

bool Fixed::operator>(Fixed& compa)
{
	return(this->toFloat() > compa.toFloat());
}

bool Fixed::operator>=(Fixed& compa)
{
	return(this->toFloat() >= compa.toFloat());
}

bool Fixed::operator!=(Fixed& compa)
{
	return(this->toFloat() != compa.toFloat());
}

bool Fixed::operator==(Fixed& compa)
{
	return(this->toFloat() == compa.toFloat());
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a.toFloat() < b.toFloat())
		return(a);
	else
		return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a.toFloat() < b.toFloat())
		return(a);
	else
		return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a.toFloat() < b.toFloat())
		return(b);
	else
		return(a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a.toFloat() < b.toFloat())
		return(b);
	else
		return(a);
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}