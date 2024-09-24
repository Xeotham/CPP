/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:34:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/24 09:05:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	add_1(int i)
{
	return (i + 1);
}

void	print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i < size - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	{
		char	str[] = "Ceci est un test";

		std::cout << "Original string: " << str << "." << std::endl;
		iter(str, 17, toupper);
		std::cout << "New string: " << str << "." << std::endl;
	}
	{
		int	arr[] = {1, 2, 10, 20, 30};

		std::cout << "Original Array: ";
		print_array(arr, 5);
		iter(arr, 5, add_1);
		std::cout << "New Array: ";
		print_array(arr, 5);
	}
}