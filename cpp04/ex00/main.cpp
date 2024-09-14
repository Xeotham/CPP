/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/14 11:38:06 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "GoofDog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== Without Wrong kitty and Goof dog =====\n" << std::endl;
	{
		const Animal*	random_animal = new Animal();
		const Animal*	doggo = new Dog();
		const Animal*	catito = new Cat();

		std::cout << doggo->getType() << std::endl;
		std::cout << catito->getType() << std::endl;
		doggo->makeSound();
		catito->makeSound();
		random_animal->makeSound();
		delete doggo;
		delete catito;
		delete random_animal;
	}
	std::cout << "\n===== With Wrong kitty and Goof Dog =====\n" << std::endl;
	{
		const WrongAnimal*	random_animal = new WrongAnimal();
		const WrongAnimal*	goofy_ahah_doggo = new GoofDog();
		const WrongAnimal*	kittyto = new WrongCat();
		GoofDog				pluto;

		std::cout << goofy_ahah_doggo->getType() << std::endl;
		std::cout << kittyto->getType() << std::endl;
		goofy_ahah_doggo->makeSound();
		kittyto->makeSound();
		random_animal->makeSound();
		delete goofy_ahah_doggo;
		delete kittyto;
		delete random_animal;
		const_cast<WrongAnimal*&>(goofy_ahah_doggo) = &pluto;
		std::cout << goofy_ahah_doggo->getType() << std::endl;
		goofy_ahah_doggo->makeSound();
	}
}