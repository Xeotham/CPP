/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:20:48 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 16:42:31 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*zomHorde;

	if (N < 1)
	{
		std::cerr << "Tried to create a something, but it's not a Zombie." << std::endl; 
		return (NULL);
	}
	zomHorde = new (std::nothrow) Zombie[N];
	if (!zomHorde)
	{
		std::cerr << "TOO MUCH ZOOOOOOOOMBIE !!!! I'M DROWNING UNDER AN OCEAN OF ZOMBIES !!! PLEASE HELP ME !!! AAAAAAAAAAAAAAAAAAAAAAAARRRARRASRSRASRGASRAGGGGGGG !!!! *died*" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		zomHorde[i].name = name;
	return (zomHorde);
}
