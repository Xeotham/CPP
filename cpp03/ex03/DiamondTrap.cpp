/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:13:27 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 08:50:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Nameless_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	this->_name = "Nameless";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Parameter Constructor called" << std::endl;
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src._name + "_clap_name"), ScavTrap(src._name), FragTrap(src._name)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap Assignation Operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::_name = src._name + "_clap_name";
		this->_name = src._name;
		this->_hitpoints = src._hitpoints;
		this->_energy_points = src._energy_points;
		this->_attack_damage = src._attack_damage;
		this->_is_guard = src._is_guard;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->_name + "_clap_name" << std::endl;
}
