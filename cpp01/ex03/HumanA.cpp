/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:56:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 14:15:24 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &n_weapon) : _weapon(n_weapon)
{
	if (name.empty())
		HumanA::_name = "Nameless";
	else
		HumanA::_name = name;
	std::cout << HumanA::_name << " is born !!!" << std::endl;
	std::cout << "Someone gave a " << HumanA::_weapon.getType() << " to " << HumanA::_name << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Nooooooooooo " << HumanA::_name << " was killed by a Zombie !!" << std::endl;
}

void	HumanA::attack()
{
	std::cout << HumanA::_name << " attacks with their " << HumanA::_weapon.getType() << std::endl;
}
