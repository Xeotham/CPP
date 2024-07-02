/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:14:34 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/02 15:54:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::new_contact()
{
	std::string	n_first_name;
	std::string	n_last_name;
	std::string	n_nickname;
	std::string	n_phone_number;
	std::string	n_darkest_secret;

	std::cout << "Enter contact's first name: ";
	std::getline(std::cin, n_first_name);
	if (!n_first_name[0] || std::cin.eof())
	{
		std::cout << std::endl << "Error : one of the fields is empty." << std::endl;
		return ;
	}
	std::cout << "Enter contact's last name: ";
	std::getline(std::cin, n_last_name);
	if (!n_last_name[0] || std::cin.eof())
	{
		std::cout << std::endl << "Error : one of the fields is empty." << std::endl;
		return ;
	}
	std::cout << "Enter contact's nickname: ";
	std::getline(std::cin, n_nickname);
	if (!n_nickname[0] || std::cin.eof())
	{
		std::cout << std::endl << "Error : one of the fields is empty." << std::endl;
		return ;
	}
	std::cout << "Enter contact's phone number: ";
	std::getline(std::cin, n_phone_number);
	if (!n_phone_number[0] || std::cin.eof())
	{
		std::cout << std::endl << "Error : one of the fields is empty." << std::endl;
		return ;
	}
	std::cout << "Enter contact's darkest secret: ";
	std::getline(std::cin, n_darkest_secret);
	if (!n_darkest_secret[0] || std::cin.eof())
	{
		std::cout << std::endl << "Error : one of the fields is empty." << std::endl;
		return ;
	}
	contacts[index].set_first_name(n_first_name);
	contacts[index].set_last_name(n_last_name);
	contacts[index].set_nickname(n_nickname);
	contacts[index].set_phone_number(n_phone_number);
	contacts[index].set_darkest_secret(n_darkest_secret);
	if (index == 7)
		index = 0;
	else
		index++;
}

std::string	format_info(std::string str)
{
	std::string	tmp;

	if (str.length() <= 10)
	{
		for (size_t i = str.length(); i < 10 ;i++)
			tmp += " ";
		tmp += str;
	}
	else
	{
		tmp = str;
		tmp.resize(9);
		tmp += ".";
	}
	return (tmp);
}

void	PhoneBook::print_contact_list()
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "|         " << i << "|";
		std::cout << format_info(contacts[i].get_first_name()) << "|";
		std::cout << format_info(contacts[i].get_last_name()) << "|";
		std::cout << format_info(contacts[i].get_nickname()) << "|" << std::endl;
	}
}

void	PhoneBook::print_contact_info(int index)
{
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
}

void	PhoneBook::search_contact()
{
	int			requested_index;
	std::string	contact_index;
	print_contact_list();
	std::cout << "Enter contact's index :";
	std::getline(std::cin, contact_index);
	if (!contact_index[0] || contact_index.size() > 1 || !isdigit(contact_index[0]) || atoi(contact_index.c_str()) > 7)
	{
		std::cout << "Error : wrong index." << std::endl;
		return ;
	}
	std::cout << std::endl;
	requested_index = atoi(contact_index.c_str());
	print_contact_info(requested_index);
}
