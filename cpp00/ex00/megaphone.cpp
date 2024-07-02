/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:36:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/02 13:05:34 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int		i;
	
	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; av[i]; i++)
		{
			for (size_t j = 0; av[i][j]; j++)
				av[i][j] = toupper(av[i][j]);
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
