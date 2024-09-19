/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:33 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/19 20:49:20 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"

int	main()
{
	try
	{
		ShruberryCreationForm	form("test");
		Bureaucrat				bob("Bob", 1);

		form.beSigned(bob);
		form.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}