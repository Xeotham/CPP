/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:16 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/01 10:31:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("")
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &new_form) : AForm("Robotomy", 72, 45), _target(new_form._target)
{
	std::srand(std::time(NULL));
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
	int	random = std::rand();

	std::cout << "Bzzzz... Vrrrr..." << std::endl;
	if (random % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &new_form)
{
	if (this != &new_form)
		this->_target = new_form._target;
	return (*this);
}
