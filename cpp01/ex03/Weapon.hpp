/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:36:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/04 15:17:04 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		void				setType(std::string type);	
		const std::string	&getType(void);
	private:
		std::string	type;
};

#endif