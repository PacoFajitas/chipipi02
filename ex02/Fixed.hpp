/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:19:01 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/11 01:29:00 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		//increment and decrement overloads
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		//Atirhmetic operators
		Fixed operator+(Fixed add);
		Fixed operator-(Fixed less);
		Fixed operator*(Fixed por);
		Fixed operator/(Fixed entre);

		//Comparison operators
		bool operator<(Fixed& compa);
		bool operator<=(Fixed& compa);
		bool operator>(Fixed& compa);
		bool operator>=(Fixed& compa);
		bool operator!=(Fixed& compa);
		bool operator==(Fixed& compa);

		//min max funcs
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif