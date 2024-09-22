/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:48:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/22 20:52:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &new_scalar)
{
	*this = new_scalar;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &new_scalar)
{
}

void	ScalarConverter::convert(const std::string str)
{
	if (str.size() == 1 && std::isprint(str.at(0)))
		is_char(str.at(0));
	else if (str.size() > 1 && check_param(str) == IS_FLOAT)
		is_float(std::stof(str.c_str()));
	else if (check_param(str) == IS_DOUBLE)
		is_double(std::stod(str));
	else if (check_param(str) == IS_INT)
		is_int(std::stoi(str));
	else if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf")
		is_inf(str);
	else if (str == "nanf" || str == "nan")
		is_nan(str);
	else
		std::cerr << "Error : wrong parameter." << std::endl;
}

void	ScalarConverter::is_char(char c)
{
	std::cout << "Value in char :	" << c << "." << std::endl;
	std::cout << "Value in int :	" << static_cast<int>(c) << "." << std::endl;
	std::cout << "Value in float :	" << static_cast<float>(c) << "f." << std::endl;
	std::cout << "Value in double :	" << static_cast<double>(c) << "." << std::endl; 
}

void	ScalarConverter::is_int(int nb)
{
	if (nb < 0 || nb > 127)
		std::cout << "Value in char :	Impossible." << std::endl;
	else
		std::cout << "Value in char :	" << static_cast<char>(nb) << "." << std::endl;
	std::cout << "Value in int :	" << nb << "." << std::endl;
	std::cout << "Value in float :	" << static_cast<float>(nb) << "f." << std::endl;
	std::cout << "Value in double :	" << static_cast<double>(nb) << "f." << std::endl;
}

void	ScalarConverter::is_float(float nb)
{
	if (nb < 0 || nb > 127)
		std::cout << "Value in char :	Impossible." << std::endl;
	else
		std::cout << "Value in char :	" << static_cast<char>(nb) << "." << std::endl;
	if (nb < static_cast<float>(INT_MIN) || nb > static_cast<float>(INT_MAX))
		std::cout << "Value in int :	Impossible." << std::endl;
	else
		std::cout << "Value in int :	" << static_cast<int>(nb) << "." << std::endl;
	std::cout << "Value in float :	" << nb << "f." << std::endl;
	std::cout << "Value in double :	" << static_cast<double>(nb) << "." << std::endl;
}

void	ScalarConverter::is_double(double nb)
{
	if (nb < 0 || nb > 127)
		std::cout << "Value in char :	Impossible." << std::endl;
	else
		std::cout << "Value in char :	" << static_cast<char>(nb) << "." << std::endl;
	if (nb < static_cast<double>(INT_MIN) || nb > static_cast<double>(INT_MAX))
		std::cout << "Value in int :	Impossible." << std::endl;
	else
		std::cout << "Value in int :	" << static_cast<int>(nb) << "." << std::endl;
	if (nb < static_cast<double>(-__FLT_MAX__) || nb > static_cast<double>(__FLT_MAX__))
		std::cout << "Value in float :	Impossible." << std::endl;
	else
		std::cout << "Value in float :	" << static_cast<double>(nb) << "f." << std::endl;
	std::cout << "Value in double :	" << nb << "." << std::endl;
}

int	ScalarConverter::check_param(std::string str)
{
	for (std::string::iterator iter = str.begin(); iter <= str.end(); iter++)
	{
		if (iter == str.end() && *iter == 'f')
			break;
		if (!std::isdigit(*iter) && *iter != '.')
			return (NOT_PARAM);
	}
	if (str.find('.') == std::string::npos)
		return (IS_INT);
	else if (str.find_first_of('.') != str.find_last_of('.'))
		return (NOT_PARAM);
	else if (str.back() == 'f')
		return (IS_FLOAT);
	else
		return (IS_DOUBLE);

}

void	ScalarConverter::is_inf(std::string str)
{
	std::cout << "Value in char :	Impossible." << std::endl;
	std::cout << "Value in int :	Impossible." << std::endl;
	if (str == "-inff" || str == "+inff")
	{
		std::cout << "Value in float :	" << str << "." << std::endl;
		std::cout << "Value in double :	Impossible." << std::endl;
	}
	else
	{
		std::cout << "Value in float :	Impossible." << std::endl;
		std::cout << "Value in double :	" << str << "." << std::endl;
	}
}

void ScalarConverter::is_nan(std::string str)
{
	std::cout << "Value in char :	Impossible." << std::endl;
	std::cout << "Value in int :	Impossible." << std::endl;
	if (str == "nanf")
	{
		std::cout << "Value in float :	nanf." << std::endl;
		std::cout << "Value in double :	Impossible." << std::endl;
	}
	else
	{
		std::cout << "Value in float :	Impossible." << std::endl;
		std::cout << "Value in double :	nan." << std::endl;
	}
}