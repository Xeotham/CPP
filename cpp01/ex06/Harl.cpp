/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:30:30 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/08 12:52:46 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	size_t	i;

	i = 0;
	for (size_t i=0; level[i]; i++)
		level[i] = tolower(level[i]);
	while (!_comments[i].empty())
	{
		if (!_comments[i].compare(level))
			break ;
		i++;
	}
	switch (i)
	{
		case	H_DEBUG:
			debug();
			std::cout << std::endl;
		case	H_INFO:
			info();
			std::cout << std::endl;
		case	H_WARNING:
			warning();
			std::cout << std::endl;
		case	H_ERROR:
			error();
			std::cout << std::endl;
			break ;
		default:
			other();
			break ;
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn\'t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn\'t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::other(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}