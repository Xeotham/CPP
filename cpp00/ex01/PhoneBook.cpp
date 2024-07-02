/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:14:34 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/01 19:28:47 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	index = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::new_contact()
{
	string	str;
	contacts[index] = Contact();
	cout << "> Enter contact's first Name: ";
	cin >> str;
	contacts[index].set_first_name(str);
	cout << endl << "> Enter contact's last name: ";
	cin >> str;
	contacts[index].set_last_name(str);
	cout << endl << "> Enter contact's nickname: ";
	cin >> str;
	contacts[index].set_nickname(str);
	cout << endl << "> Enter contact's phone number: ";
	cin >> str;
	contacts[index].set_phone_number(str);
	cout << endl << "> Enter contact's darkest secret: ";
	cin >> str;
	contacts[index].set_darkest_secret(str);
	cout << endl;
	if (index == 7)
		index = 0;
	else
		index++;
}
