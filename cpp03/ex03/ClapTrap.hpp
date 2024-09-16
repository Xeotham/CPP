/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:37:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:26:54 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public://		Constructor / Destructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		virtual	~ClapTrap();
	public://		Public methods
		void		attack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	public://		Operator overload
		ClapTrap	&operator=(const ClapTrap& src);
	protected://	Protected attributs
		int			_hitpoints;
		int			_energy_points;
		int			_attack_damage;
		std::string	_name;
};

#endif