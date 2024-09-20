/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:03:47 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 11:18:45 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "iostream"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShruberryCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &new_intern);
		~Intern();
		AForm	*makeForm(const std::string &form_type, const std::string &target);
	public:
		Intern	&operator=(const Intern &new_intern);
	private:
		const std::string _names[4] = {"shruberry creation", "robotomy request", "presidential pardon", ""};
};

#endif