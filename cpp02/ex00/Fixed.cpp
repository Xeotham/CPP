/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/27 11:08:45 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point_value = 0;
}

Fixed::Fixed(Fixed &raw)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = raw;
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

Fixed	&operator=(const Fixed &nb)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this->_fixed_point_value != nb._fixed_point_value)
		this->_fixed_point_value = nb._fixed_point_value;
	return (*this);
}
