/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:03:47 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/30 08:52:26 by mhaouas          ###   ########.fr       */
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
	public:
		AForm	*makeForm(const std::string &form_type, const std::string &target);
	public:
		Intern	&operator=(const Intern &new_intern);
	private:
		class FormCreationException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

#endif