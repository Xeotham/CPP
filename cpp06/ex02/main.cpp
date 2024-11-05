/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:58:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/07 07:29:59 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main(void)
{
	Base	*test;

	std::srand(std::time(NULL));
	try
	{
		test = generate();
		identify(test);
		identify(*test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete test;
	test = NULL;
	try
	{
		identify(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		identify(*test);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
