/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:18:04 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 10:55:01 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &new_serializer)
{
	*this = new_serializer;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &new_serializer)
{
	static_cast<void>(new_serializer);
	return (*this);
}

uintptr_t Serializer::serialize(t_data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data *>(raw));
}
