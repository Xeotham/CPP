/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:34:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/09 16:37:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	add_1(int &i)
{
	i += 1;
}

template<typename T>
void	print_value(T value)
{
	std::cout << value << std::endl;
}

void	make_upper(char &value)
{
	value = std::toupper(value);
}

int main()
{
	{
		char	str[] = "Ceci est un test";

		::iter<char>(str, 17, print_value<char>);
		::iter<char>(str, 17, make_upper);
		std::cout << str << std::endl;
	}
	{
		int	arr[] = {1, 2, 10, 20, 30};

		std::cout << "Original array:" << std::endl;
		::iter<int>(arr, 5, print_value<int>);
		::iter<int>(arr, 5, add_1);
		std::cout << "New array: " << std::endl;
		::iter(arr, 5, print_value<int>);
	}
}