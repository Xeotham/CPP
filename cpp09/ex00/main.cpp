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
	// if (ac != 2) {
	// 	std::cerr << "Wrong number of arguments (need only one arguments)." << std::endl;
	// 	return (1);
	// }
	(void)ac;
	try {
		(void)av;
		BitcoinExchange	bitcoin_exchange;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}