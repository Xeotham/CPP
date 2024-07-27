/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:27:42 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/25 17:53:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(char **av)
{
	if (!av[0] || !av[1] || !av[2])
		return ;
	file_name = av[0];
	to_find = av[1];
	replace = av[2];
}

Sed::~Sed()
{
	infile.close();
	outfile.close();
}

bool	Sed::checkArgs()
{
	if (to_find.empty())
		return (false);
	else
		return (true);
}

bool	Sed::openInfile()
{
	infile = std::ifstream(file_name);
	if (!infile.is_open())
	{
		if (outfile.is_open())
			outfile.close();
		return (false);
	}
	else
		return (true);
}

bool	Sed::openOutfile()
{
	outfile = std::ofstream(file_name + ".replace");
	if (!outfile.is_open())
	{
		if (infile.is_open())
			infile.close();
		return (false);
	}
	else
		return (true);
}

std::string	Sed::getFile(void)
{
	std::string		read_buff;
	std::string		str;
	size_t			i;

	i = 0;
	while (!infile.eof())
	{
		std::getline(infile, read_buff);
		str += read_buff;
		if (!infile.eof())
			str += "\n";
	}
	return (str);
}

std::string	Sed::replaceString(std::string str)
{
	size_t		to_find_len;
	size_t		index;
	std::string	n_str;
	std::string	tmp;

	to_find_len = to_find.size();
	tmp = str;
	n_str = "";
	index = tmp.find(to_find);
	if (index == std::string::npos)
		n_str = tmp;
	while (index != std::string::npos)
	{
		index = tmp.find(to_find);
		n_str += tmp.substr(0, index);
		if (index != std::string::npos)
			n_str += replace;
		tmp.erase(0, index + to_find_len);
	}
	return (n_str);
}

std::string	Sed::formatFile()
{
	std::string	line;
	std::string	n_line;

	line = getFile();
	n_line = replaceString(line);
	return (n_line);
}

void	Sed::printInOutfile(std::string to_print)
{
	outfile.write(to_print.c_str(), to_print.size());
}
