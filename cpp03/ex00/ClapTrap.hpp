/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:37:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:18:43 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public://	Constructor / Destructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();
	public://	Public Methods
		void		attack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	public://	Operator Overload
		ClapTrap	&operator=(const ClapTrap& src);
	private://	Private attributs
		int			_hitpoints;
		int			_energy_points;
		int			_attack_damage;
		std::string	_name;
};

#endif