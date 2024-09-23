#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Nameless")
{
	this->_grade = 150;
}


Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	this->_grade = src.getGrade();
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::promote()
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		--this->_grade;
}

void	Bureaucrat::demote()
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		++this->_grade;
}

void	Bureaucrat::signForm(AForm &to_sign)
{
	try
	{
		to_sign.beSigned(*this);
		std::cout << this->getName() << " signed "  << to_sign.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << to_sign.getName() << " because " <<  e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " <<  e.what() << std::endl;
	}
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
		const_cast<std::string &>(this->_name) = rhs.getName();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &in)
{
	out << in.getName() << ", bureaucrat grade " << in.getGrade() << ".";
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The Bureaucrat's grade was set too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The Bureaucrat's grade was set too low");
}
