/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:05:25 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/30 13:55:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>

Span::Span()
{
	std::srand(std::time(NULL));
	this->_max_value = 0;
	this->_size = 0;
	this->_storage.reserve(0);
}

Span::Span(const Span &new_span)
{
	std::srand(std::time(NULL));
	this->_max_value = new_span._max_value;
	this->_size = new_span._size;
	this->_storage = new_span._storage;
	this->_storage.reserve(new_span._max_value);
}

Span::Span(const unsigned int N)
{
	std::srand(std::time(NULL));
	this->_max_value = N;
	this->_size = 0;
	this->_storage.reserve(N);
}

Span::~Span()
{
}

const Span	&Span::operator=(const Span &new_span)
{
	if (this == &new_span)
		return (*this);
	this->_max_value = new_span._max_value;
	this->_size = new_span._size;
	this->_storage = new_span._storage;
	return (*this);
}

std::vector<int>::iterator	Span::getBegin()
{
	return (this->_storage.begin());
}

std::vector<int>::iterator	Span::getEnd()
{
	return (this->_storage.end());
}

void	Span::addNumber(int nb)
{
	if (++this->_size > this->_max_value)
		throw (Span::SpanException());
	this->_storage.push_back(nb);
}

void	Span::addNumber(std::vector<int>::iterator start, int size)
{
	u_int32_t	new_size = start - this->_storage.begin() + size;
	if (new_size > this->_max_value)
		throw (Span::SpanException());
	this->_storage.resize(this->_max_value);
	std::generate_n(start, size, Span::generateRandom);
	this->_size = new_size;
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>	tmp(this->_storage);
	int	shortest_span = __INT32_MAX__;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
	{
		if (iter + 1 != tmp.end() && *(iter + 1) - *iter < shortest_span)
			shortest_span = *(iter + 1) - *iter;
	}
	return (shortest_span);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>	tmp(this->_storage);

	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *tmp.begin());
}

int	Span::generateRandom()
{
	int	value;

	value = ((std::rand() * std::rand()) % ((std::rand() % 1000) + 1));
	if ((((std::rand() % 100) * (std::rand() % 10)) % 2) == 0)
		value *= -1;
	return (value);
}

const char	*Span::SpanException::what() const throw()
{
	return ("tried to add number when the containers is full.");
}
