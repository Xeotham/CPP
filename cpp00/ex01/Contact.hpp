/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:11:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/01 19:20:02 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

using namespace std;

class Contact
{
	public:
		Contact();
		~Contact();
		void	set_first_name(string n_first_name);
		void	set_last_name(string n_last_name);
		void	set_nickname(string nickname);
		void	set_phone_number(string phone_number);
		void	set_darkest_secret(string n_secret);
		string	get_first_name(void);
		string	get_last_name(void);
		string	get_nickname(void);
		string	get_phone_number(void);
		string	get_darkest_secret(void);


	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
};

#endif