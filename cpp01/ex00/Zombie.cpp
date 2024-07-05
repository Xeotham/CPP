/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:54:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/03 21:05:09 by mhaouas          ###   ########.fr       */
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
}

void	Zombie::announce(void)
{
	if (!Zombie::name[0])
		std::cout << "No zombie, No Brains." << std::endl;
	else
		std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
