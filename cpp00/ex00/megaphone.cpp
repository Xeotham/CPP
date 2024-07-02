/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:36:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/01 17:08:33 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int	main(int ac, char **av)
{
	int		i;
	
	i = 0;
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else
	{
		for (size_t i = 1; av[i]; i++)
		{
			for (size_t j = 0; av[i][j]; j++)
				av[i][j] = toupper(av[i][j]);
			cout << av[i];
		}
		cout << endl;
	}
	return (0);
}
