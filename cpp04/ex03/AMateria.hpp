/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:45:22 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 16:19:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		virtual ~AMateria();
	public:
		std::string const	&getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter &target);
		ICharacter const	*getOwner() const;
		void				setOwner(ICharacter &new_owner);
		void				unsetOwner();
	public:
		AMateria &operator=(const AMateria &rhs);
	protected:
		AMateria();
	protected:
		ICharacter	*_owner;
		std::string _type;
};

#endif