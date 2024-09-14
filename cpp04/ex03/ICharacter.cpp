/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:48:36 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/15 01:31:38 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

void ICharacter::equip(AMateria *m)
{
	static_cast<void>(m);
}

void ICharacter::unequip(int idx)
{
	static_cast<void>(idx);
}

void ICharacter::use(int idx, ICharacter &target)
{
	static_cast<void>(idx);
	static_cast<void>(target);
}
