/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:26:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/30 13:15:55 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed &raw);
		~Fixed();
		Fixed &operator=(const Fixed &nb);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_fixed_point_value;
		static const int	_fractional_bits = 8;
};

#endif