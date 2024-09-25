/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/25 08:59:00 by mhaouas          ###   ########.fr       */
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
	std::cout << std::endl;
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
	}
	std::cout << std::endl;
	{
		Dog	bobo, baba(bobo);
		Cat	lolo, lala;

		lala = lolo;
		bobo.think(0, "I THIIINK!!");
		baba.think(0, "Bark !!");
		lolo.think(0, "I THINK TOOOOO!!");
		lala.think(0, "Meow ??");
		std::cout << "Bobo say: " << bobo.speak(0) << ", and Baba say: " << baba.speak(0) << std::endl;
		std::cout << "Lolo say: " << lolo.speak(0) << ", and Lala say: " << lala.speak(0) << std::endl;
		baba = bobo;
		std::cout << "Bobo say: " << bobo.speak(0) << ", and Baba say: " << baba.speak(0) << std::endl;
		std::cout << "Lolo say: " << lolo.speak(0) << ", and Lala say: " << lala.speak(0) << std::endl;
		{
			bobo.think(-1, "Wooooah");
			bobo.think(100, "Ouin Ouin");
			bobo.think(99, "Waf! Waf!");
			std::cout << "Bobo activate his neurone number 99 and say: "<< bobo.speak(99) << std::endl;
		}
	}
}
