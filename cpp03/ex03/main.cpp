/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:36:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 14:14:18 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	ClapScop(void)
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

void	ScavScop(void)
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

void	FragScop(void)
{
	FragTrap	benoit("Benoit"), benoitjunior, benoitjunior2(benoit);

	benoit.highFivesGuys();
	benoit.takeDamage(99);
	benoitjunior = benoit;
	benoitjunior.takeDamage(1);
	benoitjunior.takeDamage(1);
	benoitjunior.attack("George");
	benoitjunior.highFivesGuys();
	for (size_t i = 0; i < 100 ; i++)
		benoitjunior2.attack("George");
	benoitjunior2.highFivesGuys();
}

void	DiamondScop(void)
{
	DiamondTrap	diamond("Diamond"), diamondjunior, diamondjunior2(diamond);

	diamond.whoAmI();
	diamond.attack("George");
	diamond.takeDamage(99);
	diamondjunior = diamond;
	diamondjunior.takeDamage(1);
	diamondjunior.takeDamage(1);
	diamondjunior.attack("George");
	diamondjunior.whoAmI();
	for (size_t i = 0; i < 50 ; i++)
		diamondjunior2.attack("George");
	diamondjunior2.whoAmI();
}

int main()
{
	std::cout << "===== ClapTrap Tests =====\n" << std::endl;
	ClapScop();
	std::cout << "\n===== ScavTrap Tests =====\n" << std::endl;
	ScavScop();
	std::cout << "\n===== FragTrap Tests =====\n" << std::endl;
	FragScop();
	std::cout << "\n===== DiamondTrap Tests =====\n" << std::endl;
	DiamondScop();

	ClapTrap *test = new DiamondTrap("Diamond");
	delete test;
	return (0);
}
