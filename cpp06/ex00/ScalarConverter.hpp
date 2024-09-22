/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:47:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 18:59:39 by mhaouas          ###   ########.fr       */
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
		
};



#endif
