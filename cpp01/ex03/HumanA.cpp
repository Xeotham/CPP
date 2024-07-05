/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:56:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 15:19:29 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &n_weapon) : weapon(n_weapon)
{
	HumanA::name = name;
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon.getType() << std::endl;
}
