/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:25:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/02 15:56:32 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

const static std::string	g_commands[4]{"ADD", "SEARCH", "EXIT", ""};

bool	compare_string(std::string str, PhoneBook *phone)
{
	size_t	i = 0;

	for (size_t j = 0; str[j]; j++)
		str[j] = toupper(str[j]);
	while (i < 4)
	{
		if (!str.compare(g_commands[i]))
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			(*phone).new_contact();
			break ;
		case 1:
			(*phone).search_contact();
			break ;
		case 2:
			return (false);
		case 3:
			std::cout << "Error : Wrong command." << std::endl;
			break ;
	}
	return (true);
}

int	main()
{
	PhoneBook	phone;
	std::string	commands;

	while (1)
	{
		if (std::cin.eof())
			return (1);
		std::cout << "> ";
		std::getline(std::cin, commands);
		if (!compare_string(commands, &phone))
			break ;
	}
}
