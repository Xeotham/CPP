/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/25 15:25:01 by mhaouas          ###   ########.fr       */
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
		const Animal	*random_animal = new Animal();
		const Animal	*doggo = new Dog();
		const Animal	*catito = new Cat();
		Dog				*idefix = new Dog();
		Cat				*dave_the_magical_cheese_wizard = new Cat();
		Dog				ScoobyDoo;
		Cat				Sylvester;

		std::cout << random_animal->getType() << std::endl;
		std::cout << doggo->getType() << std::endl;
		std::cout << catito->getType() << std::endl;
		std::cout << idefix->getType() << std::endl;
		std::cout << dave_the_magical_cheese_wizard->getType() << std::endl;
		doggo->makeSound();
		catito->makeSound();
		random_animal->makeSound();
		ScoobyDoo.makeSound();
		dave_the_magical_cheese_wizard->makeSound();
		delete doggo;
		delete catito;
		delete random_animal;
		delete idefix;
		delete dave_the_magical_cheese_wizard;
		std::cout << ScoobyDoo.getType() << std::endl;
		std::cout << Sylvester.getType() << std::endl;
		ScoobyDoo.makeSound();
		Sylvester.makeSound();
		idefix = &ScoobyDoo;
		idefix->makeSound();
		dave_the_magical_cheese_wizard = &Sylvester;
		dave_the_magical_cheese_wizard->makeSound();
	}
	std::cout << "\n===== With Wrong kitty and Goof Dog =====\n" << std::endl;
	{
		const WrongAnimal*	random_animal = new WrongAnimal();
		const WrongAnimal*	goofy_ahah_doggo = new GoofDog();
		const WrongAnimal*	kittyto = new WrongCat();
		GoofDog				pluto;
		WrongCat			garfield;

		std::cout << random_animal->getType() << std::endl;
		std::cout << goofy_ahah_doggo->getType() << std::endl;
		std::cout << kittyto->getType() << std::endl;
		goofy_ahah_doggo->makeSound();
		kittyto->makeSound();
		random_animal->makeSound();
		delete goofy_ahah_doggo;
		delete kittyto;
		delete random_animal;
		pluto.makeSound();
		garfield.makeSound();
		const_cast<WrongAnimal*&>(goofy_ahah_doggo) = &pluto;
		std::cout << goofy_ahah_doggo->getType() << std::endl;
		goofy_ahah_doggo->makeSound();
	}
}