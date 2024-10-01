/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:16 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/01 10:28:26 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("Nobody")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &new_form) : AForm("Presidential Pardon", 25, 5), _target(new_form._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw(AForm::FormIsntSignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::cout << "Hey you ! You're name is " << this->_target << " right ? I'm here to inform you that you've been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << "On this note, have a good day !!" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &new_form)
{
	if (this != &new_form)
		this->_target = new_form._target;
	return (*this);
}
