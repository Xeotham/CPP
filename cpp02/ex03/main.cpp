/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:25:43 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/03 12:27:16 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point	a(1.0f, 1.0f), b(5.0f, 1.0f), c(3.0f, 4.0f), point(2.0f, 2.0f), test;

	if (bsp(a,b,c,point))
		std::cout << "Is in the triangle" << std::endl;
	else
		std::cout << "Isn't in the triangle" << std::endl;
	return (0);
}
