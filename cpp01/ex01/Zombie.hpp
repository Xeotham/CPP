/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:20:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/03 21:25:53 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);
		Zombie* zombieHorde(int N, std::string name);
	private:
		std::string	name;
};
