/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:13:37 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/30 16:29:59 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	findW1(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed	w1;

	w1 = (a.getX() * (c.getY() - a.getY()))
		+ ((point.getY() - a.getY()) * (c.getX() - a.getX()))
		- (point.getX() * (c.getY() - a.getX()));
	w1 = w1 / (((b.getY() - a.getY()) * (c.getX() - a.getX()))
		- ((b.getX() - a.getX()) * (c.getY() - a.getY())));
	return (w1);
}

static Fixed	findW2(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed	w2;

	w2 = point.getY() - a.getY() - (findW1(a, b, c, point) * (b.getY() - a.getY()));
	w2 = w2 / (c.getY() - a.getY());
	return (w2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1, w2;

	w1 = findW1(a, b, c, point);
	w2 = findW2(a, b, c, point);
	if (w1 < 0 || w2 < 0 || (w1 + w2) > 1)
		return (false);
	else
		return (true);
}
