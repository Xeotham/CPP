/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:37:17 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 08:50:14 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->_name = "Nameless";
	this->_hitpoints = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Parameter Constructor called" << std::endl;
	this->_name = name;
	this->_hitpoints = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
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
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitpoints = src._hitpoints;
		this->_energy_points = src._energy_points;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (this->_hitpoints > 0 && this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_points;
	}
	else if (this->_hitpoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead! He can't attack !!" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "ClapTrap " << this->_name << " is out of energy! He can't attack !!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
		this->_hitpoints -= amount;
	}
	else
		std::cout << "The ennemy kicked " << this->_name << "'s already dead body!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " be repaired by " << amount << " points!" << std::endl;
		--this->_energy_points;
		this->_hitpoints += amount;
	}
	else if (this->_energy_points <= 0)
		std::cout << "ClapTrap " << this->_name << " can't do anything !! He's out of energy !!" << std::endl;
	else if (this->_hitpoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead! He can't be repaired!" << std::endl;
}
