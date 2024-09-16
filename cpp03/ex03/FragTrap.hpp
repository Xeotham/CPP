/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:00:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 13:30:08 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public://		Constructor / Destructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		~FragTrap();
	public://		Public methods
		void highFivesGuys(void);
	public://		Operator Overload
		FragTrap& operator=(const FragTrap& src);
	protected://	FragTrap stats
		static const int	__hitpoints = 100;
		static const int	__energy_points = 100;
		static const int	__attack_damage = 30;
};

#endif