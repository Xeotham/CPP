/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:41 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/01 19:18:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

using namespace std;

class PhoneBook
{
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void	new_contact();
	void	contact_search();
private:
	int		index;
	Contact	contacts[8];
};

#endif