/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/28 12:14:56 by mhaouas          ###   ########.fr       */
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
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_value = nb * (1 << _fractional_bits);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_value = roundf(nb * (1 << _fractional_bits));
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
	return (roundf(Fixed::toFloat()));
}

float	Fixed::toFloat(void) const
{
	return ((((float)_fixed_point_value) / (1 << _fractional_bits)));
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
