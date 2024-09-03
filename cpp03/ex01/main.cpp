/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:36:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/03 14:48:54 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "===== ClapTrap Tests =====\n" << std::endl;
	{
		ClapTrap fred("Fred"), bob("Bob"), fredjunior, bobjunior(bob);

		fredjunior = fred;
		fred.attack("George");
		bob.takeDamage(10);
		bob.takeDamage(1);
		bob.attack("George");
		bobjunior.takeDamage(9);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.beRepaired(1);
		bobjunior.takeDamage(10);
		bobjunior.attack("George");
		fredjunior.attack("Globox");
	}
	std::cout << "\n===== ScavTrap Tests =====\n" << std::endl;
	{
		ScavTrap george("George"), globox("Globox"), georgejunior, globoxjunior(globox);

		georgejunior = george;
		george.attack("Fred");
		globox.takeDamage(99);
		globox.takeDamage(1);
		globox.attack("Fred");
		globoxjunior.takeDamage(99);
		globoxjunior.beRepaired(10);
		globoxjunior.guardGate();
		globoxjunior.beRepaired(10);
		globoxjunior.guardGate();
		for (size_t i = 0; i < 50 ; i++)
			georgejunior.attack("Fred");
		georgejunior.attack("Fred");
	}
	return (0);
}
