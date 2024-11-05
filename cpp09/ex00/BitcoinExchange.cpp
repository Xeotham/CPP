/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:40:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/04 13:33:43 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {
	std::ifstream	data_base("data.csv");
	std::string		line;

	if (!data_base.is_open())
		throw (std::invalid_argument("Can't open data.csv"));
	if (!std::getline(data_base, line))
		throw (std::invalid_argument("Empty file"));
	if (line != "date,exchange_rate")
		throw (std::invalid_argument("Invalid data base header"));
	while (std::getline(data_base, line)) {
		_bitcoin_value.insert(parseLine(line));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &new_bit_exch) {
	*this = new_bit_exch;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &new_bit_exch) {
	_bitcoin_value = new_bit_exch._bitcoin_value;
	return (*this);
}

std::tm	BitcoinExchange::getDate(const std::string &line) {
	char				dash;
	std::stringstream	stream(line);
	std::tm				date;

	stream >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday;
	date.tm_year -= 1900;
	date.tm_mon -= 1;
	date.tm_hour = 1;
	date.tm_min = 0;
	date.tm_sec = 0;
	return (date);
}

std::pair<std::time_t, double>	BitcoinExchange::parseLine(const std::string &line) {
	std::tm		time;
	std::tm		time_tmp;
	double		value;
	std::time_t	t;

	if (line.find_first_of(',') == std::string::npos || (line.find_first_of(',') != line.find_last_of(',')))
		throw (std::invalid_argument("Invalid data format"));
	value = std::atof(line.substr(line.find(',') + 1).c_str());
	time = getDate(line.substr(0, line.find(',')));
	time_tmp = time;
	t = mktime(&time);
	if (time.tm_year != time_tmp.tm_year || time.tm_mon != time_tmp.tm_mon || time.tm_mday != time_tmp.tm_mday)
		throw (std::invalid_argument("Invalid date"));
	std::cout << t << std::endl;
	return (std::make_pair(t, value));
}
