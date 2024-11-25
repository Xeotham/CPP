/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:41 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/20 09:38:45 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		welcome();
		void		addHistory(const std::string &line);
		size_t		getHistorySize() const;
		std::string	getHistory(int idx);
		std::string	getError() const;
		void		setError(const std::string &error);
		void		newContact();
		void		searchContact();
		void		editContact();
	private:
		void		editContactInfo(Contact *contact);
		std::string	getContactInfo(Contact *contact, int idx);
		void		setContactinfo(Contact *contact, int idx, const std::string &value);
		std::string	getInputValue(const std::string &prompt);
		std::string getInputValueEmpty(const std::string &prompt);
		void	printContactList();
		void	printContactInfo(int index);
	private:
		std::string	_error;
		int			_index;
		Contact		_contacts[8];
		std::string	*_history;
		size_t		_history_size;
};

#endif