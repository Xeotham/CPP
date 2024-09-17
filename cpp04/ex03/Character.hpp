/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:18:36 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/17 10:05:51 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &src);
		~Character();
	public:
		std::string const	&getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		AMateria			*getMateria(int idx) const;
	public:
		Character &operator=(const Character &rhs);
	protected:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif