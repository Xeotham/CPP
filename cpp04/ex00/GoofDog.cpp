/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GoofDog.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/11 17:21:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GoofDog.hpp"

GoofDog::GoofDog() : WrongAnimal()
{
	std::cout << "GoofDog constructor called" << std::endl;
	this->_type = "GoofDog";
}

GoofDog::GoofDog(const GoofDog &src) : WrongAnimal()
{
	std::cout << "GoofDog copy constructor called" << std::endl;
	*this = src;
}

GoofDog::~GoofDog()
{
	std::cout << "GoofDog destructor called" << std::endl;
}

GoofDog &GoofDog::operator=(const GoofDog &src)
{
	std::cout << "GoofDog assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void GoofDog::makeSound() const
{
	std::cout << "Vroom Vroum" << std::endl;
}
