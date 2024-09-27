/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:18:36 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/27 09:57:12 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "Nameless";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_name = name;
}

Character::Character(const Character &src)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this == this->_inventory[i]->getOwner())
			delete this->_inventory[i];
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	if (m->getOwner())
	{
		std::cerr << "The materia is already equiped by someone else." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << this->getName() << " equiped a " << m->getType() << " materia in his inventory." << std::endl; 
			m->setOwner(*this);
			return ;
		}
	}
	std::cout << this->getName() << " couldn't equip a " << m->getType() << " materia because his inventory is full." << std::endl; 
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->_inventory[idx]->unsetOwner();
		std::cout << this->getName() << " unequiped a " << this->_inventory[idx]->getType() << " materia." << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "* do nothing *" << std::endl;
}

AMateria	*Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return (NULL);
	else
		return (this->_inventory[idx]);
}
