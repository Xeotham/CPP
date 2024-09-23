/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:06 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 11:18:05 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>
#include <ctime>

Base::~Base()
{
}

Base	*generate(void)
{
	std::srand(std::time(NULL));

	int	random = std::rand() % 3;

	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cerr << e.what() << std::endl;
	}
}