/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 10:50:37 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public://	Constructors / Destructors
		Fixed();
		Fixed(const Fixed &raw);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();
	public://	Operator overload
		Fixed	&operator=(const Fixed &nb);
	public://	Methods
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
	private://	Private attributs
		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
};

std::ostream &operator << (std::ostream &out, Fixed const &fx);
#endif