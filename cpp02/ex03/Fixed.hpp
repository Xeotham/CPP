/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:17:22 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public://	Constructor / Destructor
		Fixed();
		Fixed(const Fixed &raw);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();
	public://	Public Methods
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed		&min(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static Fixed		&max(Fixed &first, Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);
	public://	Operator Overload
	//				Assignement Operator
		Fixed	&operator=(const int &nb);
		Fixed	&operator=(const float &nb);
		Fixed	&operator=(const Fixed &nb);
	//	Fixed Comparison operator :
		bool	operator>(const Fixed &nb);
		bool	operator>=(const Fixed &nb);
		bool	operator<(const Fixed &nb);
		bool	operator<=(const Fixed &nb);
		bool	operator==(const Fixed &nb);
		bool	operator!=(const Fixed &nb);
	//	Fixed Arithmetic operator :
		Fixed	operator+(const Fixed &nb);
		Fixed	operator-(const Fixed &nb);
		Fixed	operator*(const Fixed &nb);
		Fixed	operator/(const Fixed &nb);
	//	Fixed Increment/decrement operator :
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
	private://	Private attributs
		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
};

std::ostream	&operator << (std::ostream &out, Fixed const &fx);

#endif