/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:28:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/24 15:30:32 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main()
{
	{
		Array<int>	test(10);

		test[0] = 0;
		test[1] = 1;

		std::cout << test[0] << std::endl;
		std::cout << test[1] << std::endl;
		try
		{
			test[-1];
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			test[10];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			test[1000];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << test << std::endl;
	}
}