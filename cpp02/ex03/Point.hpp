/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:13:47 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:15:35 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public://	Constructor / Destructor
		Point();
		Point(const Point &raw);
		Point(const float x, const float y);
		~Point();
	public://	Public methods
		Fixed	getX()	const;
		Fixed	getY()	const;
	public://	Operator Overload
		Point	&operator=(const Point &new_point);
	private://	Private attributs
		const Fixed	_x;
		const Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif