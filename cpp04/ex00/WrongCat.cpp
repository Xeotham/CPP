/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/11 17:21:11 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Wrong Cat constructor called" << std::endl;
	this->_type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Wrong Cat assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}
