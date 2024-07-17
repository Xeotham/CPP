/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:01:44 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 14:16:55 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	if (name.empty())
		HumanB::_name = "nameless";
	else
		HumanB::_name = name;
	HumanB::_weapon = NULL;
	std::cout << HumanB::_name << " is born !!!" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Nooooooooooo " << HumanB::_name << " was killed by a Zombie !!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	HumanB::_weapon = &weapon;
	std::cout << "Someone gave a " << HumanB::_weapon->getType() << " to " << HumanB::_name << std::endl;

}

void	HumanB::attack()
{
	if (!HumanB::_weapon)
		std::cout << HumanB::_name << " doesn't have a weapon ! Give him one before he die !!" << std::endl;
	else
		std::cout << HumanB::_name << " attacks with their " << HumanB::_weapon->getType() << std::endl;
}
