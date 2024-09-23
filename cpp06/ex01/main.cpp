/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:17:31 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 10:56:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main()
{
	try
	{
		t_data		*data = new t_data;
		uintptr_t	intptr;

		data->data = 10;
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