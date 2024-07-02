/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:35:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/01 19:12:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::set_first_name(string n_first_name)
{
	Contact::first_name = n_first_name;
}

void	Contact::set_last_name(string n_last_name)
{
	Contact::last_name = n_last_name;
}

void	Contact::set_nickname(string n_nickname)
{
	Contact::nickname = n_nickname;
}

void	Contact::set_phone_number(string n_phone_number)
{
	Contact::phone_number = n_phone_number;
}

void	Contact::set_darkest_secret(string n_secret)
{
	Contact::darkest_secret = n_secret;
}

string	Contact::get_first_name(void)
{
	return Contact::first_name;
}

string	Contact::get_last_name(void)
{
	return Contact::last_name;
}

string	Contact::get_nickname(void)
{
	return Contact::nickname;
}

string	Contact::get_phone_number(void)
{
	return Contact::phone_number;
}

string	Contact::get_darkest_secret(void)
{
	return Contact::darkest_secret;
}