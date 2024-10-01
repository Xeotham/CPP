/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:35:48 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/30 13:41:35 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		try
		{
			Span	sp;
			sp.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Span	sp(10);

			sp.addNumber(sp.getBegin(), 11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Span	sp(10);

			sp.addNumber(1);
			sp.addNumber(sp.getBegin() + 1, 9);
			for (std::vector<int>::iterator iter = sp.getBegin(); iter != sp.getEnd(); iter++)
				std::cout << *iter << ", ";
			std::cout << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			sp.addNumber(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
}