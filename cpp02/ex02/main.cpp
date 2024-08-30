/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:25:43 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/30 12:27:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed	a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	c;
	Fixed	d;

	c = 24.45f;
	d = 150;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c + d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;
	return 0;
}