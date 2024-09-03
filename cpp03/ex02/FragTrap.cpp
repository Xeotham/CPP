/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:00:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/03 15:13:55 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap Parameter Constructor called" << std::endl;
	this->_name = name;
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap Assignation Operator called" << std::endl;
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitpoints > 0 && this->_energy_points > 0)
		std::cout << "Hey Guys !! It's " << this->_name << " !! high fives guys !!" << std::endl;
	else if (this->_hitpoints <= 0)
		std::cout << "Hey Guys !! It's " << this->_name << " !! I'm dead, I can't high fives you, sorry !!" << std::endl;
	else
		std::cout << "Hey Guys !! It's " << this->_name << " !! I'm out of energy, I can't high fives you, sorry !!" << std::endl;
}
