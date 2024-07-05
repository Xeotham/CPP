/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:21:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 16:57:17 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

void	error_handle(int error)
{
	switch (error)
	{
		case 0:
			std::cerr << "Wrong number of args : ./Sed_is_for_losers [filename] \
[str to replace] [str to replace with]" << std::endl;
			break;
		case 1:
			std::cerr << "Failed to open the infile" << std::endl;
			break ;
		case 2:
			std::cerr << "Failed to create the outfile" << std::endl;
			break ;
	}
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		error_handle(0);
	Sed	sed(av + 1);
	if (!sed.openInfile())
		error_handle(1);
	if (!sed.openOutfile())
		error_handle(2);
	sed.printInOutfile(sed.formatFile());
}
