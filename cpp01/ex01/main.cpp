/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:20:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 13:14:12 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*ZomArray;

	ZomArray = ZomArray->zombieHorde(-8, "Klark");
	ZomArray = ZomArray->zombieHorde(0, "Johne");
	ZomArray = ZomArray->zombieHorde(8, "Philibert");
	for (int i = 0; i < 8; i++)
		ZomArray[i].announce();
	delete [] ZomArray;
}
