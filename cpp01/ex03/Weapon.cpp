/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:50:39 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 15:17:02 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string n_type)
{
	type = n_type;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	Weapon::type = type;
}

const std::string	&Weapon::getType()
{
	return (Weapon::type);
}
