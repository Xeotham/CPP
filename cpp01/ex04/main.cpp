/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:21:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/25 17:54:46 by mhaouas          ###   ########.fr       */
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
	Sed			sed(av + 1);
	bool		error = true;
	std::string	formated_text;

	if (ac != 4)
		error = error_handle(0);
	if (error && !sed.openInfile())
		error = error_handle(1);
	if (error && !sed.openOutfile())
		error = error_handle(2);
	if (error && !sed.checkArgs())
		error = error_handle(3);
	if (error)
		sed.printInOutfile(sed.formatFile());
	else
		return (1);
}
