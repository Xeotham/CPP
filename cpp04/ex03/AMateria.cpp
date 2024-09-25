/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:45:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/25 16:28:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_owner = NULL;
	this->_type = "";
}

AMateria::AMateria(std::string const &type)
{
	this->_owner = NULL;
	this->_type = type;
}

AMateria::AMateria(const AMateria &src)
{
	this->_owner = NULL;
	*this = src;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &new_materia)
{
	if (this != &new_materia)
		this->_type = new_materia._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	static_cast<void>(target);
}

AMateria *AMateria::clone() const
{
	return (NULL);
}

ICharacter const	*AMateria::getOwner() const
{
	return (this->_owner);
}

void	AMateria::setOwner(ICharacter &new_owner)
{
	if (!this->_owner)
		this->_owner = &new_owner;
}

void	AMateria::unsetOwner()
{
	this->_owner = NULL;
}
