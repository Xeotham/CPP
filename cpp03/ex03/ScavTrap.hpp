/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:23:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:31:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public://		Constructor / Destructor
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
	public://		Public methods
		void	attack(std::string const & target);
		void	guardGate();
	public://		Operator overload
		ScavTrap	&operator=(const ScavTrap& src);
	protected://	Protected attributs / ScavTrap stats
		bool				_is_guard;
		static const int	__hitpoints = 100;
		static const int	__energy_points = 50;
		static const int	__attack_damage = 20;
};

#endif