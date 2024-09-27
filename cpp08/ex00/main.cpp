/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:47:22 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/27 15:20:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

std::vector<int>

int	main()
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
