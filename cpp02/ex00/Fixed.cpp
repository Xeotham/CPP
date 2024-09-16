/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 10:43:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &raw)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &nb)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this->_fixed_point_value != nb.getRawBits())
		this->_fixed_point_value = nb.getRawBits();
	return (*this);
}
