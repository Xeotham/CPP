/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:13:45 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/03 12:24:35 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() :_x(0), _y(0)
{
}

Point::Point(const Point &raw) : _x(raw._x), _y(raw._y)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Fixed	Point::getX()	const
{
	return (_x);
}

Fixed	Point::getY()	const
{
	return (_y);
}

Point	&Point::operator=(const Point &new_point)
{
	if (static_cast<Fixed>(this->_x) != static_cast<Fixed>(new_point._x))
		static_cast<Fixed>(this->_x) = new_point._x;
	if (static_cast<Fixed>(this->_y) != static_cast<Fixed>(new_point._y))
		static_cast<Fixed>(this->_y) = new_point._y;
	return (*this);
}
