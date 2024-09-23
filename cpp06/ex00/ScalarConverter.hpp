/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:47:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 09:56:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(const std::string str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &new_scalar);
		ScalarConverter	&operator=(const ScalarConverter &new_scalar);
	private:
		static void	is_char(char c);
		static void	is_int(long int i);
		static void	is_float(float f);
		static void	is_double(double d);
		static void	is_inf(std::string str);
		static void	is_nan();
		static int	check_param(const std::string str);
	private:
		enum	e_param
		{
			NOT_PARAM = -1,
			IS_INT,
			IS_FLOAT,
			IS_DOUBLE
		};
};



#endif
