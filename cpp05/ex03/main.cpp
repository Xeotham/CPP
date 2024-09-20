/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:33 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 10:52:11 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		ShruberryCreationForm	form1("Garden");
		PresidentialPardonForm	form2("Bob");
		RobotomyRequestForm		form3("Bender");
		Bureaucrat				bob("Bob", 1);

		form1.beSigned(bob);
		form2.beSigned(bob);
		form3.beSigned(bob);
		form1.execute(bob);
		form2.execute(bob);
		form3.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		ShruberryCreationForm	form("Garden");
		Bureaucrat				fred("Fred", 1);

		form.execute(fred);
		form.signForm();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		ShruberryCreationForm	form("Garden");
		Bureaucrat				globox("Globox", 150);

		std::cout << form << std::endl;
		form.beSigned(globox);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		RobotomyRequestForm	form("Baba");
		Bureaucrat			globglob("Globglob", 1);
		Bureaucrat			glabglab("Glabglab", 150);
		
		form.beSigned(globglob);
		form.execute(glabglab);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}