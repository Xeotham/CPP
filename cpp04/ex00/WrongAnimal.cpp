/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/11 17:20:13 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal constructor called" << std::endl;
	this->_type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Wrong Animal assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some wrong random wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}
