/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:23:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/20 17:01:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->name = "Nameless";
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_is_guard = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parameter Constructor called" << std::endl;
	this->_name = name;
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_is_guard = false;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap Assignation Operator called" << std::endl;
	if (this != &src)
	{
		this->_is_guard = src._is_guard;
		this->_name = src._name;
		this->_hitpoints = src._hitpoints;
		this->_energy_points = src._energy_points;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	if (this->_hitpoints > 0 && this->_energy_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_points;
	}
	else if (this->_hitpoints <= 0)
		std::cout << "ScavTrap " << this->_name << " is already dead! He can't attack !!" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "ScavTrap " << this->_name << " is out of energy! He can't attack !!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_is_guard == false && this->_hitpoints > 0)
		std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
	else if (this->_is_guard == true && this->_hitpoints > 0)
		std::cout << "ScavTrap " << this->_name << " has exited from Gate keeper mode" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " is already dead! He can't enter or exit from Gate keeper mode!" << std::endl;
		return ;
	}
	this->_is_guard = !this->_is_guard;
}
