/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:59:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 13:08:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const std::string name, int sign_grade, int _exec_grade);
		Form(const Form &new_form);
		~Form();
	public:
		bool				getIsSigned() const;
		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat &signer);
	public:
		Form	&operator=(const Form &new_form);
	private:
		bool				_is_signed;
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
	private:
		class	GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw(); 
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &in);

#endif