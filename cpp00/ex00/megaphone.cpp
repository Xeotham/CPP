/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:36:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 10:40:57 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int			i;
	std::string	str;
	std::string	to_print;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; av[i]; i++)
			str += av[i];
		for (std::string::iterator iter = str.begin(); iter != str.end(); iter++)
			*iter = std::toupper(*iter);
		std::cout << str << std::endl;
	}
	return (0);
}
