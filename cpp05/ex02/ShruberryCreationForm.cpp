/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:00:16 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/19 20:45:58 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm() : AForm("Shruberry", 145, 137), _target("")
{
}

ShruberryCreationForm::ShruberryCreationForm(const std::string target) : AForm("Shruberry", 145, 137), _target(target)
{
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &new_form) : AForm("Shruberry", 145, 137), _target(new_form._target)
{
}

ShruberryCreationForm::~ShruberryCreationForm()
{
}

void	ShruberryCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false || executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::ofstream	outfile((this->_target + "_shruberry").c_str());

	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠖⠒⠢⣄⣀⡀⣀⣀⠀⡠⠔⠒⠒⢤⡀			" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⡇⠀⠀⠀⠁⠠⡋⠀⠀⠙⠦⠀⠀⠀⠀⣧⠤⣀⠀⠀⠀	" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⡠⠖⠊⠑⠲⣄⣀⣠⠖⠘⠛⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⢸⠇		" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⣸⣇⡀⠀⠀⠈⠁⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠋⠲⣄		" << std::endl;
	outfile << "⠀⠀⠀⠀⣠⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠂⠀	" << std::endl;
	outfile << "⠀⠀⠀⢀⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⢱⠀⠀⠀⠀⠀⠀⠀⠐⠺⡄⠀⠀	" << std::endl;
	outfile << "⠀⡠⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡀⠀⢀⡼⠀⠀⠀⠀⠀⠀⠀⠀⢀⡇⠀	" << std::endl;
	outfile << "⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠈⠉⠁⡹⠀⠀⠀⣄⣀⡠⠟⢘⣯⣀⠀	" << std::endl;
	outfile << "⠸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡷⠺⡍⠒⣿⣀⣠⡀⠀⠀⠀⠀⠀⠈⠀⠈⡷	" << std::endl;
	outfile << "⠸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡷⠺⡍⠒⣿⣀⣠⡀⠀⠀⠀⠀⠀⠈⠀⠈⡷	" << std::endl;
	outfile << "⠀⢸⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⢀⣶⠺⡁⠀⠙⠚⠀⠁⡏⢧⣀⡄⠀⠀⠀⠀⠐⠒⣇	" << std::endl;
 	outfile << "⠀⠸⣄⣀⣰⠀⠀⠀⠀⠀⠀⠲⣟⣿⡦⣷⠀⠀⠀⠀⢠⠁⣸⣿⣷⢶⡆⢀⣤⡀⣠⡾⠁	" << std::endl;
	outfile << "⠀⠀⠀⠀⠱⣀⠀⢀⡱⠄⠤⠜⠋⠻⡄⠀⠀⠀⠀⠀⣸⣴⡿⣏⠀⢀⣭⣁⣀⡽⠁⠀⠀	" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⠀⣿⡼⠁⠀⠉⠉⠀⠀⠀⠀			" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀⢿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣧⠀⠀⠀⠀⠸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⠀⠀⠀⠈⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠒⢋⣁⡀⠀⠀⠀⠀⠀⠘⠢⢄⣀⠀⠀⠀⠀⠀⠀⠀		" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠁⠉⠙⠒⠤⣘⣗⠒⠒⠒⠚⠛⠃⠀⠀⠀⠀⠀		" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀				" << std::endl;
}

ShruberryCreationForm	&ShruberryCreationForm::operator=(const ShruberryCreationForm &new_form)
{
	if (this != &new_form)
		this->_target = new_form._target;
	return (*this);
}
