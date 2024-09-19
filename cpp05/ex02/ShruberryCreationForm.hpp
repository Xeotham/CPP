/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:16 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/19 20:35:13 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_H
# define SHRUBERRYCREATIONFORM_H

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
	public:
		ShruberryCreationForm();
		ShruberryCreationForm(const std::string target);
		ShruberryCreationForm(const ShruberryCreationForm &new_form);
		~ShruberryCreationForm();
	public:
		virtual void	execute(Bureaucrat const &executor) const;
	public:
		ShruberryCreationForm	&operator=(const ShruberryCreationForm &new_form);
	private:
		std::string	_target;	
};

#endif