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

typedef std::pair<std::time_t, std::pair<std::string, double> > t_data;
typedef std::map<std::time_t, std::pair<std::string, double> > t_data_base;


class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &new_bit_exch);
		~BitcoinExchange();
	public:
		BitcoinExchange	&operator=(const BitcoinExchange &new_bit_exch);
	public:
		void	testFile(const std::string &file);
	private:
		t_data		parseLine(const std::string &line);
		std::tm		getDate(const std::string &line);
		double		getValue(const std::string &line);
		void		checkValue(const std::string &value);
	private:
		t_data_base	_bitcoin_value;
};

#endif