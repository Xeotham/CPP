/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:54:15 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/03 20:56:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new(std::nothrow) Zombie;
	if (!newZombie)
		return (NULL);
	newZombie->name = name;
	return (newZombie);
}
