/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:50:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/03 21:25:45 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{

	public:
		Zombie();
		~Zombie();
		void	announce(void);
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);
	private:
		std::string	name;
};

#endif