/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/09 14:50:13 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &raw)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = raw;
}

Fixed::Fixed(const int nb)
{
	_fixed_point_value = nb;
}

Fixed::Fixed(const float nb)
{
	_fixed_point_value = nb;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_fixed_point_value);
}

float	Fixed::toFloat(void) const
{
	return (roundf(_fixed_point_value));
}

Fixed	&Fixed::operator=(const Fixed &nb)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this->_fixed_point_value != nb._fixed_point_value)
		this->_fixed_point_value = nb._fixed_point_value;
	return (*this);
}

std::ostream &operator << (std::ostream &out, Fixed const &fx)
{
	out << fx.toFloat();
	return (out);
}
