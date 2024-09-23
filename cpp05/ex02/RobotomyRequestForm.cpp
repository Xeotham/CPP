/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:16 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 07:48:03 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &new_form) : AForm("Robotomy", 72, 45), _target(new_form._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw(AForm::FormIsntSignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::srand(std::time(NULL));
	int	random = std::rand();

	std::cout << "Bzzzz... Vrrrr..." << std::endl;
	if (random % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &new_form)
{
	if (this != &new_form)
		this->_target = new_form._target;
	return (*this);
}
