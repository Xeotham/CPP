/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:37:17 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/03 13:01:45 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Parameter Constructor called" << std::endl;
	this->Name = name;
	this->Hitpoints = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap Assignation Operator called" << std::endl;
	this->Name = src.Name;
	this->Hitpoints = src.Hitpoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (this->Hitpoints > 0 && this->Energy_points > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attack " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
		--this->Energy_points;
	}
	else if (this->Hitpoints <= 0)
		std::cout << "ClapTrap " << this->Name << " is already dead! He can't attack !!" << std::endl;
	else if (this->Energy_points <= 0)
		std::cout << "ClapTrap " << this->Name << " is out of energy! He can't attack !!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " take " << amount << " points of damage!" << std::endl;
		this->Hitpoints -= amount;
	}
	else
		std::cout << "The ennemy kicked " << this->Name << "'s already dead body!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy_points > 0 && this->Hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " be repaired by " << amount << " points!" << std::endl;
		--this->Energy_points;
		this->Hitpoints += amount;
	}
	else if (this->Energy_points <= 0)
		std::cout << "ClapTrap " << this->Name << " can't do anything !! He's out of energy !!" << std::endl;
	else if (this->Hitpoints <= 0)
		std::cout << "ClapTrap " << this->Name << " is already dead! He can't be repaired!" << std::endl;
}
