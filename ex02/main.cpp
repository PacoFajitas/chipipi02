/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:15:14 by tfiguero          #+#    #+#             */
/*   Updated: 2024/05/11 01:32:57 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b;
Fixed c(2.5f);
Fixed d(2);

c  = c*d;
// a = Fixed(1234.4321f);
std::cout << "++a is " << ++a << std::endl;
std::cout << "b is " << b++ << std::endl;
std::cout << "b after b++ is " << b << std::endl;
std::cout << "--a is " << --a << std::endl;
std::cout << "b is " << b-- << std::endl;
std::cout << "b after b-- is " << b << std::endl;
if(c <= d)
{
	std::cout << "Soy mentirijilla jiji" << std::endl;
}else{
	std::cout << "Tamo joya" << std::endl;
}
d = 4;
if(c >= d)
{
	std::cout << "Soy mentirijilla jiji" << std::endl;
}else{
	std::cout << "Tamo joya" << std::endl;
}
std::cout << "min between c and d is " << Fixed::min(c, d) << std::endl;
std::cout << "max between c and d is " << Fixed::max(c, d) << std::endl;
return 0;
}