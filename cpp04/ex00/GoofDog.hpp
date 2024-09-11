/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GoofDog.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/11 17:12:03 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOOFDOG_HPP
# define GOOFDOG_HPP

#include "WrongAnimal.hpp"

class	GoofDog : public WrongAnimal
{
	public:
		GoofDog();
		GoofDog(const GoofDog &other);
		GoofDog &operator=(const GoofDog &other);
		~GoofDog();
		void makeSound() const;
};

#endif