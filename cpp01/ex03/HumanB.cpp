/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:01:44 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 15:19:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
	HumanB::weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}

void	HumanB::attack()
{
	if (!HumanB::weapon)
		std::cout << HumanB::name << " doesn't have a weapon ! Give him one before he die !!" << std::endl;
	else
		std::cout << HumanB::name << " attacks with their " << HumanB::weapon->getType() << std::endl;
}
