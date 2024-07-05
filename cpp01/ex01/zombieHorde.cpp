/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:20:48 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 13:13:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*zomHorde;

	if (N < 1)
	{
		std::cerr << "Tried to create a non zombie." << std::endl; 
		return (NULL);
	}
	zomHorde = new(std::nothrow) Zombie[N];
	if (!zomHorde)
	{
		std::cerr << "Zombies wasn't create." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		zomHorde[i].name = name;
	return (zomHorde);
}
