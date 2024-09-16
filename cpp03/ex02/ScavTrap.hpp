/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:23:54 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:24:22 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public://	Constructor / Destructor
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
	public://	Public methods
		void	attack(std::string const & target);
		void	guardGate();
	public://	Operator Overload
		ScavTrap	&operator=(const ScavTrap& src);
	private://	Private attributs
		bool	_is_guard;
};

#endif