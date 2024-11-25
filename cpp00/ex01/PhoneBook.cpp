/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:14:34 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/20 09:40:57 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iomanip>

PhoneBook::PhoneBook() {
	_index = 0;
	_history = NULL;
	_history_size = 0;
}

PhoneBook::~PhoneBook() {
	if (_history)
		delete [] _history;
}

void PhoneBook::welcome() {
	std::cout << "\033c\033[34;1mWelcome to" << std::endl;
	std::cout << "	______ _                     ______             _            " << std::endl;
	std::cout << "	| ___ \\ |                    | ___ \\           | |         " << std::endl;
	std::cout << "	| |_/ / |__   ___  _ __   ___| |_/ / ___   ___ | | __        " << std::endl;
	std::cout << "	|  __/| '_ \\ / _ \\| '_ \\ / _ \\ ___ \\/ _ \\ / _ \\| |/ / " << std::endl;
	std::cout << "	| |   | | | | (_) | | | |  __/ |_/ / (_) | (_) |   <         " << std::endl;
	std::cout << "	\\_|   |_| |_|\\___/|_| |_|\\___\\____/ \\___/ \\___/|_|\\_\\" << std::endl;
	std::cout << "                                               Made by mhaouas." << std::endl;
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[31;1;4mCommands:\033[0m" << std::endl;
	std::cout << "\033[31;1m	- \033[31;1;4mADD:\033[0m\033[32m You can add a new contact to you PhoneBook.\033[0m" << std::endl;
	std::cout << "\033[31;1m	- \033[31;1;4mSEARCH:\033[0m\033[32m You can get info about your contacts.\033[0m" << std::endl;
	std::cout << "\033[31;1m	- \033[31;1;4mEDIT:\033[0m\033[32m You can edit the info of a contact.\033[0m" << std::endl;
	std::cout << "\033[31;1m	- \033[31;1;4mEXIT:\033[0m\033[32m simply exit your PhoneBook.\033[0m" << std::endl;
	std::cout << std::endl;
	if (!this->_error.empty())
		std::cerr << "\033[31;1m" << this->_error << "\033[0m" << std::endl;
}

void PhoneBook::addHistory(const std::string &line) {
	if (_history_size > static_cast<size_t>(std::numeric_limits<int>::max()))
		return ;

	std::string	*tmp;

	tmp = new(std::nothrow) std::string[++_history_size];
	if (!tmp)
		return ;
	for (size_t i = 0; i < _history_size - 1; i++)
		tmp[i + 1] = _history[i];
	if (_history)
		delete [] _history;
	_history = tmp;
	_history[0] = line;
}

size_t PhoneBook::getHistorySize() const {
	return (_history_size);
}

std::string PhoneBook::getHistory(int idx) {
	if (idx >= 0 && static_cast<size_t>(idx) < _history_size && _history) {
		std::cout << "index: " << idx << " value: " << _history[idx] << std::endl;
		return (_history[idx]);
	}
	else if (static_cast<size_t>(idx) >= _history_size && _history)
		return (_history[_history_size - 1]);
	else
		return ("");
}

std::string PhoneBook::getError() const {
	return (this->_error);
}

void PhoneBook::setError(const std::string &error) {
	this->_error = error;
}


std::string PhoneBook::getInputValue(const std::string &prompt) {
	std::string	value;

	std::cout << prompt;
	if (!std::getline(std::cin, value))
		throw (false);
	if (!value[0] || std::cin.eof()) {
		this->_error =  "Error : one of the fields is empty.";
		return ("");
	}
	for (std::string::const_iterator iter = value.begin(); iter != value.end(); iter++) {
		if (!std::isprint(*iter)) {
			this->_error =  "Error: one of the characters is not printable.";
			return ("");
		}
	}
	return (value);
}

std::string PhoneBook::getInputValueEmpty(const std::string &prompt) {
	std::string	value;

	std::cout << prompt;
	if (!std::getline(std::cin, value))
		throw (false);
	if (std::cin.eof()) {
		std::cerr << "\033[31;1mError : one of the fields is empty.\033[0m" << std::endl;
		return ("");
	}
	for (std::string::const_iterator iter = value.begin(); iter != value.end(); iter++) {
		if (!std::isprint(*iter)) {
			std::cerr <<  "\033[31;1mError: one of the characters is not printable.\033[0m" << std::endl;
			return ("");
		}
	}
	return (value);
}

void	PhoneBook::newContact()
{
	std::string	n_first_name;
	std::string	n_last_name;
	std::string	n_nickname;
	std::string	n_phone_number;
	std::string	n_darkest_secret;

	n_first_name = getInputValue("Enter contact's first name: ");
	if (n_first_name.empty())
		return ;
	n_last_name = getInputValue("Enter contact's last name: ");
	if (n_last_name.empty())
		return ;
	n_nickname = getInputValue("Enter contact's nickname: ");
	if (n_nickname.empty())
		return ;
	n_phone_number = getInputValue("Enter contact's phone number: ");
	if (n_phone_number.empty())
		return ;
	n_darkest_secret = getInputValue("Enter contact's darkest secret: ");
	if (n_darkest_secret.empty())
		return ;
	_contacts[_index].set_first_name(n_first_name);
	_contacts[_index].set_last_name(n_last_name);
	_contacts[_index].set_nickname(n_nickname);
	_contacts[_index].set_phone_number(n_phone_number);
	_contacts[_index].set_darkest_secret(n_darkest_secret);
	if (_index == 7)
		_index = 0;
	else
		++_index;
	this->_error = "";
}

void	PhoneBook::printContactList()
{
	std::cout << "\033[36;1m";
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "|\033[36;1;3m" << std::setfill(' ') << std::setw(10) << i << "\033[0m\033[36;1m";
		std::cout << "|\033[36;1;3m" << std::setfill(' ') << std::setw(10)
			<< ((_contacts[i].get_first_name().size() > 10) ? _contacts[i].get_first_name().substr(0, 9) + "." : _contacts[i].get_first_name()) << "\033[0m\033[36;1m";
		std::cout << "|\033[36;1;3m" << std::setfill(' ') << std::setw(10)
			<< ((_contacts[i].get_last_name().size() > 10) ? _contacts[i].get_last_name().substr(0, 9) + "." : _contacts[i].get_last_name()) << "\033[0m\033[36;1m";
		std::cout << "|\033[36;1;3m" << std::setfill(' ') << std::setw(10)
			<< ((_contacts[i].get_nickname().size() > 10) ? _contacts[i].get_nickname().substr(0, 9) + "." : _contacts[i].get_nickname()) << "\033[0m\033[36;1m"
			<< "|" << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "\033[0m";
}

void	PhoneBook::printContactInfo(int index)
{
	this->_error = "\033[0m\033[37;1mContact'info:\n";
	this->_error += "First name:     \t" + _contacts[index].get_first_name() + "\n";
	this->_error += "Last name:      \t" + _contacts[index].get_last_name() + "\n";
	this->_error += "Nickname:       \t" + _contacts[index].get_nickname() + "\n";
	this->_error += "Phone number:   \t" + _contacts[index].get_phone_number() + "\n";
	this->_error +=  "Darkest secret: \t" + _contacts[index].get_darkest_secret() + "\n";
}

void	PhoneBook::searchContact()
{
	int			requested_index;
	std::string	contact_index;

	printContactList();
	std::cout << "Enter contact's index :";
	if (!std::getline(std::cin, contact_index))
		return ;
	if (!contact_index[0] || contact_index.size() > 1 || !isdigit(contact_index[0]) || std::atoi(contact_index.c_str()) > 7
		|| this->_contacts[std::atoi(contact_index.c_str())].get_first_name().empty())
	{
		this->_error = "Error : wrong index.";
		return ;
	}
	std::cout << std::endl;
	requested_index = std::atoi(contact_index.c_str());
	printContactInfo(requested_index);
}

std::string PhoneBook::getContactInfo(Contact *contact, int idx) {
	switch (idx) {
		case 0:
			return (contact->get_first_name());
		case 1:
			return (contact->get_last_name());
		case 2:
			return (contact->get_nickname());
		case 3:
			return (contact->get_phone_number());
		case 4:
			return (contact->get_darkest_secret());
		default:
			return ("");
	}
}

void PhoneBook::setContactinfo(Contact *contact, int idx, const std::string &value) {
	switch (idx) {
		case 0:
			return contact->set_first_name(value);
		case 1:
			 return contact->set_last_name(value);
		case 2:
			return contact->set_nickname(value);
		case 3:
			return contact->set_phone_number(value);
		case 4:
			return contact->set_darkest_secret(value);
		default:
			return ;
	}
}


void	PhoneBook::editContactInfo(Contact *contact) {
	short						i = 0;
	std::string					value;
	static const std::string	prompts[] = {
		"First name:     \t",
		"Last name:      \t",
		"Nickname:       \t",
		"Phone number:   \t",
		"Darkest secret: \t"};
	this->_error = "\033[0m\033[37;1mSimply press enter to keep the same value.\n";
	while (i < 5) {
		welcome();
		for (short j = 0; j < i; ++j)
			std::cout << prompts[j] << getContactInfo(contact, j) << std::endl;
		value = getInputValueEmpty(prompts[i]);
		if (!value.empty())
			setContactinfo(contact, i, value);
		++i;
	}
	this->_error = "";
}

void	PhoneBook::editContact() {
	std::string	index_str;
	Contact		*contact;

	printContactList();
	std::cout << "Enter contact's index :";
	if (!std::getline(std::cin, index_str))
		return ;
	if (!index_str[0] || index_str.size() > 1 || !isdigit(index_str[0]) || std::atoi(index_str.c_str()) > 7
		|| this->_contacts[std::atoi(index_str.c_str())].get_first_name().empty())
	{
		this->_error = "Error : wrong index.";
		return ;
	}
	contact = &_contacts[std::atoi(index_str.c_str())];
	editContactInfo(contact);
}
