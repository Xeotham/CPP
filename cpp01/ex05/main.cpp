/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:21:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/08 12:39:39 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	std::cout << std::endl;
	harl.complain("fhdsjkfhskd");
	harl.complain("");
	harl.complain(" debug ");
	harl.complain(" \binfo\t\b");
	harl.complain("error   ");
	harl.complain("\001\002warning\001\002");
	harl.complain("erro");
	harl.complain("in");
	std::cout << std::endl;
	harl.complain("DEBUG");
	harl.complain("InFo");
	harl.complain("WARning");
	harl.complain("ErroR");
}
