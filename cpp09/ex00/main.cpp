/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:33:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/04 11:35:03 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	try {
		if (ac != 2)
			throw (std::invalid_argument("Error: Wrong number of arguments (need only one arguments)."));
		BitcoinExchange	bitcoin_exchange;
		bitcoin_exchange.testFile(av[1]);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
}