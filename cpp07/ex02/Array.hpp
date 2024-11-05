/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:29:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/09 14:42:43 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <cstring>

template <typename T>
class Array
{
	public:
		Array();
		Array(const Array &new_array);
		Array(unsigned int n);
		~Array();
	public:
		unsigned int	size() const;
	public:
		Array		&operator=(const Array &new_array);
		T			&operator[](std::size_t idx);
		const T		&operator[](std::size_t idx) const;
	private:
		T				*_arr;
		unsigned int	_size;
	private:
		class	ArrayException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

template <typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> &in);

#include "Array.tpp"

#endif