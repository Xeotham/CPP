/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:30:26 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/25 18:30:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

class Harl
{
    public:
        Harl();
        ~Harl();
		void	complain(std::string level);
    private:
        void	debug(void);
        void	info(void);
        void	warning(void);
		void	error(void);
		void	other(void);
	private:
		std::string	_comments[5] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
};

#endif