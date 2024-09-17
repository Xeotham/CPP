/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:44:42 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/17 10:06:03 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		MateriaSource	*src = new MateriaSource();
		Character		globglob("Globglob");
		Character		glabglab("Glabglab");
		AMateria		*tmp;
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		globglob.equip(tmp);
		tmp = src->createMateria("cure");
		globglob.equip(tmp);
		tmp = src->createMateria("ice");
		globglob.equip(tmp);
		globglob.use(0, glabglab);
		globglob.use(2, glabglab);
		tmp = globglob.getMateria(0);
		globglob.unequip(0);
		globglob.use(0, glabglab);
		globglob.use(3, glabglab);
		globglob.use(120, glabglab);
		delete src;
		delete tmp;
	}
	return (0);
}