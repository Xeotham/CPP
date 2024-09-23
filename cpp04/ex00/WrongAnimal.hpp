/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:53:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 14:27:47 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();
	public:
		void	makeSound() const;
		std::string		getType() const;
	public:
		WrongAnimal &operator=(const WrongAnimal &other);
	protected:
		std::string _type;
};

#endif