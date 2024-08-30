/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/30 11:58:18 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &raw)
{
	(*this) = raw;
}

Fixed::Fixed(const int nb)
{
	_fixed_point_value = nb * (1 << _fractional_bits);
}

Fixed::Fixed(const float nb)
{
	_fixed_point_value = roundf(nb * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
}

int	Fixed::toInt(void) const
{
	return (roundf(Fixed::toFloat()));
}

float	Fixed::toFloat(void) const
{
	return ((static_cast<float>(_fixed_point_value) / (1 << _fractional_bits)));
}

/* ===== Overload ===== */
//	Comaprison operators

Fixed	&Fixed::operator=(const Fixed &nb)
{
	if (this->_fixed_point_value != nb._fixed_point_value)
		this->_fixed_point_value = nb._fixed_point_value;
	return (*this);
}

Fixed	&Fixed::operator=(const int &nb)
{
	if (this->_fixed_point_value != nb * (1 << _fractional_bits))
		this->_fixed_point_value = nb * (1 << _fractional_bits);
	return (*this);
}

Fixed	&Fixed::operator=(const float &nb)
{
	if (this->_fixed_point_value != roundf(nb * (1 << _fractional_bits)))
		this->_fixed_point_value = roundf(nb * (1 << _fractional_bits));
	return (*this);
}

bool	Fixed::operator>(const Fixed &right)
{
	return (this->getRawBits() > right.getRawBits());
}

bool	Fixed::operator<(const Fixed &right)
{
	return (this->getRawBits() < right.getRawBits());
}

bool	Fixed::operator>=(const Fixed &right)
{
	return (this->getRawBits() >= right.getRawBits());
}

bool	Fixed::operator<=(const Fixed &right)
{
	return (this->getRawBits() <= right.getRawBits());
}

bool	Fixed::operator==(const Fixed &right)
{
	return (this->getRawBits() == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right)
{
	return (this->getRawBits() != right.getRawBits());
}

//	arithmetic Operator

Fixed	Fixed::operator+(const Fixed &nb)
{
	Fixed	new_nb(this->toFloat() + nb.toFloat());
	return (new_nb);
}

Fixed	Fixed::operator-(const Fixed &nb)
{
	Fixed	new_nb(this->toFloat() - nb.toFloat());
	return (new_nb);
}

Fixed	Fixed::operator*(const Fixed &nb)
{
	Fixed	new_nb(this->toFloat() * nb.toFloat());
	return (new_nb);
}

Fixed	Fixed::operator/(const Fixed &nb)
{
	Fixed	new_nb(this->toFloat() / nb.toFloat());
	return (new_nb);
}

std::ostream &operator << (std::ostream &out, Fixed const &fx)
{
	out << fx.toFloat();
	return (out);
}

//	increment/decrement operator

Fixed	&Fixed::operator++()
{
	this->_fixed_point_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_fixed_point_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

// overload function

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	Fixed	n_first = first;
	Fixed	n_second = second;

	if (n_first < n_second)
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	Fixed	n_first = first;
	Fixed	n_second = second;

	if (n_first > n_second)
		return (first);
	else
		return (second);
}
