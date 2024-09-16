/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:36:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 12:50:39 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
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
	return (0);
}