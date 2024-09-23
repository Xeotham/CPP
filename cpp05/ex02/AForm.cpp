/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:00:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 07:47:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Nameless Form"), _sign_grade(150), _exec_grade(150)
{
	this->_is_signed = false;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw(AForm::GradeTooHighException());
	else if (this->_sign_grade > 150 || this->_sign_grade > 150)
		throw(AForm::GradeTooLowException());
	this->_is_signed = false;
}

AForm::AForm(const AForm &new_form) : _name(new_form.getName()), _sign_grade(new_form.getSignGrade()), _exec_grade(new_form.getExecGrade())
{
	*this = new_form;
}

AForm::~AForm()
{
}

bool	AForm::getIsSigned() const
{
	return (this->_is_signed);
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade() const
{
	return (this->_exec_grade);
}


void	AForm::setIsSigned(const bool new_is_signed)
{
	this->_is_signed = new_is_signed;
}

void	AForm::setSignGrade(const int new_sign_grade)
{
	const_cast<int &>(this->_sign_grade) = new_sign_grade;
}

void	AForm::setExecGrade(const int new_exec_grade)
{
	const_cast<int &>(this->_exec_grade) = new_exec_grade;
}


void	AForm::beSigned(Bureaucrat &signer)
{
	if (this->getIsSigned() == true)
		return ;
	if (signer.getGrade() > this->getSignGrade())
		throw (AForm::GradeTooLowException());
	this->_is_signed = true;
}

AForm	&AForm::operator=(const AForm &new_form)
{
	if (this != &new_form)
	{
		this->_is_signed = new_form.getIsSigned();
		const_cast<std::string &>(this->_name) = new_form.getName();
		const_cast<int &>(this->_sign_grade) = new_form.getSignGrade();
	}
	return (*this);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("The grade was set too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("The grade was set too low.");
}

const char	*AForm::FormIsntSignedException::what() const throw()
{
	return ("The Form isn't signed.");
}

std::ostream	&operator<<(std::ostream &out, const AForm &in)
{
	std::cout << in.getName() << ", sign grade: " << in.getSignGrade() << ", execution grade: " << in.getExecGrade() << ".";
	return (out);
}