/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:25:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/03 17:04:31 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <csignal>
#include "PhoneBook.hpp"


#define						NB_CMD 6
const static char			up[] = {27, 91, 65, 0};
const static char			down[] = {27, 91, 66, 0};
const static std::string	g_commands[NB_CMD] = {up, down, "ADD", "SEARCH", "EDIT", "EXIT"};
static		 int			g_index = -1;
static		 bool			g_sig = false;
static		 std::string	g_history;

static bool	compare_string(std::string str, PhoneBook &phone)
{
	size_t	i = 0;

	for (size_t j = 0; str[j]; j++)
		str[j] = std::toupper(str[j]);
	while (i < NB_CMD)
	{
		if (str == g_commands[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			g_index += (static_cast<size_t>(g_index + 1) < phone.getHistorySize() ? 1 : 0);
			g_history = phone.getHistory(g_index);
			break;
		case 1:
			g_index -= (g_index - 1 >= -1 ? 1 : 0);
			g_history = phone.getHistory(g_index);
			break;
		case 2:
			phone.addHistory(str);
			phone.newContact();
			g_index = -1;
			g_history.clear();
			break ;
		case 4:
			phone.addHistory(str);
			phone.editContact();
			g_index = -1;
			g_history.clear();
			break;
		case 3:
			phone.addHistory(str);
			phone.searchContact();
			g_index = -1;
			g_history.clear();
			break ;
		case 5:
			return (false);
		default:
			if (g_sig)
				throw false;
			if (!str.empty())
				phone.setError("Error : Wrong command.");
			else
				phone.setError("");
			g_index = -1;
			g_history.clear();
			break ;
	}
	return (true);
}

static void	sigHandle(int sig) {
	static_cast<void>(sig);
	g_sig = true;
	std::cout << std::endl;
	throw false;
}

int	main() {
	try {
		PhoneBook	phone;
		std::string	commands;

		std::signal(SIGINT, sigHandle);
		std::signal(SIGKILL, sigHandle);
		std::signal(SIGQUIT, sigHandle);

		while (!g_sig)
		{
			if (std::cin.eof())
				throw true;
			phone.welcome();
			std::cout << "> ";
			if (g_index >= 0 && !g_history.empty())
				std::cout << g_history;
			if (!std::getline(std::cin, commands))
				throw true;
			if (g_index >= 0 && !g_history.empty() && commands != up && commands != down)
				commands = g_history + commands;
			if (!compare_string(commands, phone))
				throw true;
		}
	}
	catch (bool state) {
		if (!state)
			return (1);
		return (0);
	}

}
