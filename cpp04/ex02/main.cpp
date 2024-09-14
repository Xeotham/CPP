/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/14 12:39:05 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define MAX_ANIMALS 10

int main()
{
	const Animal	*scooby_doo = new Dog();
	const Animal	*goofy = new Dog();
	const Animal	*garfield = new Cat();
	const Animal	*puss_in_boots = new Cat();

	scooby_doo->makeSound();
	goofy->makeSound();
	garfield->makeSound();
	puss_in_boots->makeSound();

	delete scooby_doo;
	delete goofy;
	delete garfield;
	delete puss_in_boots;
}
