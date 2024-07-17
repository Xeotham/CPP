/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:20:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 13:52:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	Zombie::name = "";
}

Zombie::~Zombie()
{
	if (!name.empty())
		std::cout << "The zombie named " << Zombie::name << " died (again)." << std::endl;
}

void	Zombie::announce(void)
{
	if (!Zombie::name[0])
		std::cout << "No zombie, No Brains." << std::endl;
	else
		std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new(std::nothrow) Zombie;
	if (!newZombie)
		return (NULL);
	newZombie->name = name;
	return (newZombie);
}

void	Zombie::randomChump(std::string name)
{
	Zombie	newZombie;

	newZombie.name = name;
	newZombie.announce();
}
