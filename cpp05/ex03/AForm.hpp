/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:59:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 07:48:29 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		virtual	~AForm();
	public:
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		const std::string	getName() const;
		void				setIsSigned(const bool new_signed);
		void				setSignGrade(const int new_sign_grade);
		void				setExecGrade(const int new_exec_grade);
		void				beSigned(Bureaucrat &signer);
		virtual void		execute(Bureaucrat const &executor) const = 0;
	public:
		AForm	&operator=(const AForm &new_form);
	protected:
		AForm();
		AForm(const std::string name, int sign_grade, int _exec_grade);
		AForm(const AForm &new_form);
	private:
		bool				_is_signed;
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
	protected:
		class	GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw(); 
		};
		class	FormIsntSignedException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &in);

#endif