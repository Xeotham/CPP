/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:03:56 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 08:21:20 by mhaouas          ###   ########.fr       */
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
	int			type = -1;
	std::string	n_form_type = form_type;
	const std::string names[4] = {"shruberry creation", "robotomy request", "presidential pardon", ""};

	for (std::string::iterator iter = n_form_type.begin(); iter != n_form_type.end(); iter++)
		*iter = std::tolower(*iter);
	for (int i = 0; i < 3; i++)
	{
		if (n_form_type == names[i])
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
			throw (Intern::FormCreationException());
	}
}

Intern	&Intern::operator=(const Intern &new_intern)
{
	static_cast<void>(new_intern);
	return (*this);
}

const char	*Intern::FormCreationException::what()	const throw()
{
	return ("This type of form isn't available.");
}
