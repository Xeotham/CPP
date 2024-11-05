/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:17:31 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/07 07:27:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main()
{
	std::srand(std::time(NULL));
	try
	{
		t_data		*data = new t_data;
		uintptr_t	intptr;

		data->data = std::rand() % 1000;
		std::cout << "Data before serialization: " << data->data << std::endl;
		intptr = Serializer::serialize(data);
		std::cout << "Data after serialization: " << Serializer::deserialize(intptr)->data << std::endl;
		std::cout << "Serialize data: " << intptr << std::endl;
		delete data;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}