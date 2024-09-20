/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:03:56 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 11:30:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &new_intern)
{
	*this = new_intern;
}


Intern::~Intern()
{
}

AForm	*Intern::makeForm(const std::string &form_type, const std::string &target)
{
	int	type = -1;

	for (int i = 0; i < 3; i++)
	{
		if (form_type == this->_names[i])
		{
			type = i;
			break ;
		}
	}
	switch (type)
	{
		case 0:
			return (new ShruberryCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "The form doesn't existe." << std::endl;
	}
}

Intern	&Intern::operator=(const Intern &new_intern)
{
}
