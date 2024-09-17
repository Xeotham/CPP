/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 16:15:14 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define MAX_ANIMALS 10

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		Animal*	animal_refuge[MAX_ANIMALS];

		for (int i = 0; i < MAX_ANIMALS; i++)
		{
			if (i % 2 == 0)
				animal_refuge[i] = new Dog();
			else
				animal_refuge[i] = new Cat();
		}
		for (int i = 0; i < MAX_ANIMALS; i++)
		{
			animal_refuge[i]->makeSound();
			delete animal_refuge[i];
		}
		return 0;
	}
}
