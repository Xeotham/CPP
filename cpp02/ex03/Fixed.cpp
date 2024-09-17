/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/17 11:14:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &raw)
{
	// std::cout << "Copy constructor called" << std::endl;
	(*this) = raw;
}

Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	_fixed_point_value = nb * (1 << _fractional_bits);
}

Fixed::Fixed(const float nb)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixed_point_value = roundf(nb * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

Fixed	&Fixed::operator=(const Fixed &nb)
{
	// std::cout << "Copy Fixed assignement operator called" << std::endl;
	if (this != &nb)
		this->_fixed_point_value = nb._fixed_point_value;
	return (*this);
}

Fixed	&Fixed::operator=(const int &nb)
{
	// std::cout << "Copy Int assignement operator called" << std::endl;
	if (this->_fixed_point_value != nb * (1 << _fractional_bits))
		this->_fixed_point_value = nb * (1 << _fractional_bits);
	return (*this);
}

Fixed	&Fixed::operator=(const float &nb)
{
	// std::cout << "Copy Float assignement operator called" << std::endl;
	if (this->_fixed_point_value != roundf(nb * (1 << _fractional_bits)))
		this->_fixed_point_value = roundf(nb * (1 << _fractional_bits));
	return (*this);
}

//	Comaprison operators
bool	Fixed::operator>(const Fixed &right)
{
	// std::cout << "Greater than operator called" << std::endl;
	return (this->getRawBits() > right.getRawBits());
}

bool	Fixed::operator<(const Fixed &right)
{
	// std::cout << "Smaller than operator called" << std::endl;
	return (this->getRawBits() < right.getRawBits());
}

bool	Fixed::operator>=(const Fixed &right)
{
	// std::cout << "Greater or equal than operator called" << std::endl;
	return (this->getRawBits() >= right.getRawBits());
}

bool	Fixed::operator<=(const Fixed &right)
{
	// std::cout << "Smaller or equal than operator called" << std::endl;
	return (this->getRawBits() <= right.getRawBits());
}

bool	Fixed::operator==(const Fixed &right)
{
	// std::cout << "Strictly equal to operator called" << std::endl;
	return (this->getRawBits() == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right)
{
	// std::cout << "Isn't equal to operator called" << std::endl;
	return (this->getRawBits() != right.getRawBits());
}

//	arithmetic Operator

Fixed	Fixed::operator+(const Fixed &nb)
{
	Fixed	new_nb;

	new_nb._fixed_point_value = this->getRawBits() + nb.getRawBits();
	return (new_nb);
}

Fixed	Fixed::operator-(const Fixed &nb)
{
	Fixed	new_nb;
	
	new_nb._fixed_point_value = this->getRawBits() - nb.getRawBits();
	return (new_nb);
}

Fixed	Fixed::operator*(const Fixed &nb)
{
	Fixed	new_nb;
	
	new_nb._fixed_point_value = (this->getRawBits() * nb.getRawBits())
		/ (1 << _fractional_bits);
	return (new_nb);
}

Fixed	Fixed::operator/(const Fixed &nb)
{
	Fixed	new_nb;

	if (nb.getRawBits() == 0)
	{
		if (this->getRawBits() >= 0)
			new_nb._fixed_point_value = 2147483647;
		else
			new_nb._fixed_point_value = -2147483648;
	}
	else
		new_nb._fixed_point_value = (this->getRawBits() << _fractional_bits)
			/ nb.getRawBits();
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
