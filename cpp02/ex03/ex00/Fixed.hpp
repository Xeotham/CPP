/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 10:07:34 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public://	Construcor / Destructor
		Fixed();
		Fixed(const Fixed &raw);
		~Fixed();
	public://	Operator overload
		Fixed &operator=(const Fixed &nb);
	public://	Methods
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private://	Privates attributs
		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
};

#endif