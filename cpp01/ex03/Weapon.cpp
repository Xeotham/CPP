/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:50:39 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 14:19:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string n_type)
{
	if (n_type.empty())
		Weapon::_type = "Some unknown weapon";
	else
		Weapon::_type = n_type;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	if (type.empty())
		Weapon::_type = "Some unidentified weapon";
	else
		Weapon::_type = type;
}

const std::string	&Weapon::getType()
{
	return (Weapon::_type);
}
