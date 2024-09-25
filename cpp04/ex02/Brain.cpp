/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:37:44 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/25 08:46:04 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
	*this = other;
}

void	Brain::setIdea(int idx, const std::string &str)
{
	if (idx < 0 || idx >= 100)
	{
		std::cerr << "Sorry but you haven't selected the right neurone." << std::endl;
		return ;
	}
	this->_ideas[idx] = str;
}

std::string	Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cerr << "Sorry but you haven't selected the right neurone." << std::endl;
		return ("");
	}
	return (this->_ideas[idx]);
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
