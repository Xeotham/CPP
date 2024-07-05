/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:57:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 13:08:07 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	Zombie1;
	Zombie	*Zombie2;

	Zombie1.randomChump("Fred");
	Zombie1.announce();
	Zombie2 = Zombie2->newZombie("Patrice");
	if (Zombie2)
		Zombie2->announce();
	Zombie2->randomChump("Globox");
	if (Zombie2)
		Zombie2->announce();
	delete Zombie2;
}
