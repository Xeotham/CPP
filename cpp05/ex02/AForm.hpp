/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:59:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/18 15:14:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class	AForm
{
	public:
		AForm();
		AForm(const std::string name, int sign_grade, int _exec_grade);
		AForm(const AForm &new_form);
		~AForm();
	public:
		bool				getIsSigned() const;
		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		Bureaucrat			getSigner() const;
		void				beSigned(Bureaucrat &signer);
		void				signForm();
	public:
		AForm	&operator=(const AForm &new_form);
	private:
		bool				_is_signed;
		Bureaucrat			_signer;
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

std::ostream	&operator<<(std::ostream &out, const AForm &in);

#endif