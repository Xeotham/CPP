/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:00:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 13:09:05 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Nameless Form"), _sign_grade(150), _exec_grade(150)
{
	this->_is_signed = false;
}

Form::Form(const std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw(Form::GradeTooHighException());
	else if (this->_sign_grade > 150 || this->_sign_grade > 150)
		throw(Form::GradeTooLowException());
	this->_is_signed = false;
}

Form::Form(const Form &new_form) : _name(new_form.getName()), _sign_grade(new_form.getSignGrade()), _exec_grade(new_form.getExecGrade())
{
	*this = new_form;
}

Form::~Form()
{
}

bool	Form::getIsSigned() const
{
	return (this->_is_signed);
}

const std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void	Form::beSigned(Bureaucrat &signer)
{
	if (this->getIsSigned() == true)
		return ;
	if (signer.getGrade() > this->getSignGrade())
		throw (Form::GradeTooLowException());
	this->_is_signed = true;
}

Form	&Form::operator=(const Form &new_form)
{
	if (this != &new_form)
	{
		this->_is_signed = new_form.getIsSigned();
		const_cast<std::string &>(this->_name) = new_form.getName();
		const_cast<int &>(this->_sign_grade) = new_form.getSignGrade();
		const_cast<int &>(this->_exec_grade) = new_form.getExecGrade();
	}
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("The grade was set too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("The grade was set too low.");
}

std::ostream	&operator<<(std::ostream &out, const Form &in)
{
	std::cout << in.getName() << ", sign grade: " << in.getSignGrade() << ", execution grade: " << in.getExecGrade() << ".";
	return (out);
}
