/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:19:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/15 01:31:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

void IMateriaSource::learnMateria(AMateria *m)
{
	static_cast<void>(m);
}

AMateria *IMateriaSource::createMateria(std::string const &type)
{
	static_cast<void>(type);
	return (NULL);
}
