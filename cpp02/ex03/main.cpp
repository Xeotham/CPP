/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:25:43 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/11 12:02:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

static void	print_triangle(bool bsp)
{
	if (bsp)
		std::cout << "Is in the triangle" << std::endl;
	else
		std::cout << "Isn't in the triangle" << std::endl;
}

int main( void )
{
	Point	a(1.0f, 1.0f), b(5.0f, 1.0f), c(3.0f, 4.0f), point1(2.0f, 2.0f), point2(4.0f, 3.0f), point3(2.0f, 1.0f), point4(3.97f, 1.76f), test;

	test = point1;
	std::cout << "Original Point" << point1.getX() << " " << point1.getY() << std::endl;
	std::cout << "Test Point: " << test.getX() << " " << test.getY() << std::endl;
	print_triangle(bsp(a,b,c,point1));
	std::cout << std::endl;
	print_triangle(bsp(a,b,c,point2));
	std::cout << std::endl;
	print_triangle(bsp(a,b,c,a));
	std::cout << std::endl;
	print_triangle(bsp(a,b,c,b));
	std::cout << std::endl;
	print_triangle(bsp(a,b,c,c));
	std::cout << std::endl;
	print_triangle(bsp(a,b,c,point3));
	std::cout << std::endl;
	print_triangle(bsp(a,b,c,point4));
	return (0);
}
