/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:22:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/25 17:52:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

class Sed
{
	public:
		Sed(char **av);
		~Sed();
		bool		openInfile(void);
		bool		openOutfile(void);
		bool		checkArgs(void);
		std::string	formatFile(void);
		void		printInOutfile(std::string to_print);
	private:
		std::string		file_name;
		std::string		to_find;
		std::string		replace;
		std::ifstream	infile;
		std::ofstream	outfile;	
	private:
		std::string		replaceString(std::string str);
		std::string		getFile(void);
};
