/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:33 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 08:23:34 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Intern	frank;

		frank.makeForm("TEST", "TEST");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Intern		glob;
		Bureaucrat	bob("Bob", 1);
		AForm		*form;

		form = glob.makeForm("shruberry creation", "test");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = glob.makeForm("SHrUbERry CREAtIOn", "Test2");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = glob.makeForm("Presidential Pardon", "Fred");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = glob.makeForm("Robotomy Request", "Didi");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Intern	glab;
		AForm	*form;

		form = glab.makeForm("SHRuberry CrEaTiOn", "Bruuuuuuuh");
		std::cout << *form << std::endl;
		delete form;
		form = glab.makeForm("PreSIdeNTIal PaRdOn", "President");
		std::cout << *form  << std::endl;
		delete form;
		form = glab.makeForm("RoBOTomY ReQuEsT", "Robot");
		std::cout << *form << std::endl;
		delete form;
		form = glab.makeForm("Roobotomy Request", "mmmh");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}