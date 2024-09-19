/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:33 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/18 15:14:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	fred("Fred", 1), bob("Bob", 150);
		AForm		form1("Form 1", 1), form2(form1), form3;

		std::cout << form1 << std::endl;
		form1.signForm();
		form1.beSigned(fred);
		form1.signForm();
		form1.beSigned(bob);
		form1.signForm();
		form3 = form1;
		std::cout << form1.getSigner().getName() << std::endl;
		std::cout << form2.getSigner().getName() << std::endl;
		std::cout << form3.getSigner().getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		AForm	bob("Bob", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		AForm	globglob("GlobGlob", 151);
		std::cout << globglob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	glabglab("Glabglab", 100);
		AForm		glabform("Glab Form", 1);

		std::cout << glabglab << std::endl;
		std::cout << glabform << std::endl;
		glabform.beSigned(glabglab);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}