/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:47:22 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/30 09:53:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomIntVector()
{
	std::vector<int>	vect;
	int					value;

	std::srand(std::time(NULL));
	for (int i = 0; i < 100; i++)
	{
		value = (std::rand() % ((std::rand() % 1000) + 1));
		if ((((std::rand() % 100) * (std::rand() % 10)) % 2) == 0)
			value *= -1;
		vect.push_back(value);
	}
	return (vect);
}

int	main()
{
	{
		std::vector<int> vect;

		vect.push_back(1);
		vect.push_back(10);
		vect.push_back(-1000);
		vect.push_back(42);
		vect.push_back(800);
		vect.push_back(69);
		vect.push_back(18);
		vect.push_back(-96);
		vect.push_back(35383773);
		easyfind(vect, 42);
		easyfind(vect, 78);
	}
	std::cout << std::endl;
	{
		std::vector<int> vect = generateRandomIntVector();
		easyfind(vect, vect.at(10));
		easyfind(vect, 42);
		easyfind(vect, 69);
		easyfind(vect, 132);
		easyfind(vect, -456);
	}
}
