/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:21:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 16:36:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool	error_handle(int error)
{
	std::cerr << "Error: ";
	switch (error)
	{
		case 0:
			std::cerr << "Wrong number of args : ./Sed_is_for_losers [filename] \
[str to replace] [str to replace with]." << std::endl;
			return (false);
		case 1:
			std::cerr << "Failed to open the infile." << std::endl;
			return (false);
		case 2:
			std::cerr << "Failed to create the outfile." << std::endl;
			return (false);
		case 3:
			std::cerr << "Wrong args." << std::endl;
			return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	std::string	formated_text;
	bool		error = true;

	if (ac != 4)
		error = error_handle(0);
	Sed	sed(av + 1);
	if (!sed.openInfile())
		error = error_handle(1);
	if (!sed.openOutfile())
		error = error_handle(2);
	if (!sed.checkArgs())
		error = error_handle(3);
	if (error)
		sed.printInOutfile(sed.formatFile());
	else
		return (1);
}
