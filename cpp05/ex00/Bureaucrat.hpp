#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
	public:
		std::string const	getName() const;
		int					getGrade() const;
		void				promote();
		void				demote();
	public:
		Bureaucrat	&operator=(Bureaucrat const & rhs);
	private:
		int					_grade;
		const std::string	_name;
	private:
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat &in);

#endif