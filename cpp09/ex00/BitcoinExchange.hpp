/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:40:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/04 13:32:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &new_bit_exch);
		~BitcoinExchange();
	public:
		BitcoinExchange	&operator=(const BitcoinExchange &new_bit_exch);
	private:
		std::map<std::time_t, double>	_bitcoin_value;
	private:
		class	OpenException : public std::exception
		{
			const char	*what() const throw();
		};
};

#endif