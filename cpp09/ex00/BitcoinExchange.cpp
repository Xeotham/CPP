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
#include <cstring>

BitcoinExchange::BitcoinExchange() {
	std::ifstream	data_base("data.csv");
	std::string		line;

	if (!data_base.is_open())
		throw (std::invalid_argument("Can't open data.csv"));
	if (!std::getline(data_base, line))
		throw (std::invalid_argument("Empty file (data.csv)"));
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

	std::memset(&date, 0, sizeof(date));
	stream >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday;
	date.tm_year -= 1900;
	date.tm_mon -= 1;
	date.tm_hour = 1;
	date.tm_min = 0;
	date.tm_sec = 0;
	return (date);
}

t_data	BitcoinExchange::parseLine(const std::string &line) {
	double		value;
	std::tm		time;
	std::tm		time_tmp;
	std::time_t	t;

	if (line.find_first_of(',') == std::string::npos || (line.find_first_of(',') != line.find_last_of(',')))
		throw (std::invalid_argument("Invalid data format"));
	value = std::atof(line.substr(line.find(',') + 1).c_str());
	if (value < 0)
		throw (std::invalid_argument("value in data.scv must be positive."));
	time = getDate(line.substr(0, line.find(',')));
	time_tmp = time;
	t = mktime(&time);
	if (time.tm_year != time_tmp.tm_year || time.tm_mon != time_tmp.tm_mon || time.tm_mday != time_tmp.tm_mday)
		throw (std::invalid_argument("Invalid date"));
	return (std::make_pair(t, std::make_pair(line.substr(0, line.find(',')), value)));
}

double	BitcoinExchange::getValue(const std::string &line) {
	double	value;

	if (line.at(0) == '-' && line.size() > 1)
		throw (std::invalid_argument("value must be positive."));
	if (line.find_first_not_of("0123456789.") != std::string::npos)
		throw (std::invalid_argument("wrong value format."));
	value = std::atof(line.c_str());
	if (value > 1000)
		throw (std::invalid_argument("too large a number."));
	return (value);
}

void	BitcoinExchange::checkValue(const std::string &value) {
	if (value.find(" | ") == std::string::npos)
		throw (std::invalid_argument("Bad input => " + value + "."));

	std::string				date_str(value.substr(0, value.find(" | ")));
	std::string				value_str(value.substr(value.find(" | ") + 3));
	double					value_d = getValue(value_str);
	std::tm					time = getDate(date_str);
	std::tm					time_tmp = time;
	std::time_t				date = mktime(&time);
	t_data_base::iterator	iter;

	if (time.tm_year != time_tmp.tm_year || time.tm_mon != time_tmp.tm_mon || time.tm_mday != time_tmp.tm_mday)
		throw (std::invalid_argument("Invalid date in input => " + date_str + "."));
	iter = _bitcoin_value.lower_bound(date);
	if (iter == _bitcoin_value.end() || (iter->first > date && iter != _bitcoin_value.begin()))
		--iter;
	else if (iter->first > date && iter == _bitcoin_value.begin())
		throw (std::invalid_argument("No data available for this date."));
	std::cout << iter->second.first << " => " << value_d << " = " << iter->second.second * value_d<< std::endl;
}

void BitcoinExchange::testFile(const std::string &file) {
	std::ifstream	input(file.c_str());
	std::string		line;

	if (!input.is_open())
		throw (std::invalid_argument("Can't open " + file));
	if (!std::getline(input, line))
		throw (std::invalid_argument("Empty file (" + file + ")"));
	if (line != "date | value")
		throw (std::invalid_argument("Invalid input file header"));
	while (std::getline(input, line)) {
		try {
			checkValue(line);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

