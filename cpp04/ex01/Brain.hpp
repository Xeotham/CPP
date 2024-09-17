/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:37:36 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/16 16:10:54 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
	public:
		Brain &operator=(const Brain &other);
	public:
		std::string	ideas[100];
};

#endif