/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:54:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 13:47:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	if (Zombie::name.empty())
		std::cout << "No zombie, No Brains." << std::endl;
	else
		std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
