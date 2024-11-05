/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:28:57 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/09 15:23:51 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	// std::cout << "Default constructor called." << std::endl;
	try
	{
		this->_arr = new T [0];
		this->_size = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
Array<T>::Array(const Array &new_array)
{
	// std::cout << "Copy constructor called." << std::endl;
	try
	{
		this->_arr = new T [0];
		this->_size = 0;
		*this = new_array;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	// std::cout << "Parameter constructor called." << std::endl;
	try
	{
		this->_arr = new T [n];
		this->_size = n;
		std::memset(this->_arr, 0, sizeof(T) * n);
	}
	catch(const std::exception& e)
	{
		throw (e);
	}
}

template <typename T>
Array<T>::~Array()
{
	// std::cout << "Default destructor called." << std::endl;
	delete [] this->_arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
	// std::cout << "size() called." << std::endl;
	return (this->_size);
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &new_array)
{
	// std::cout << "copy operator called." << std::endl;
	if (this == &new_array)
		return (*this);
	if (this->size() != new_array.size())
	{
		try
		{
			delete [] this->_arr;
			this->_arr = new T [new_array.size()];
			this->_size = new_array.size();
		}
		catch(const std::exception& e)
		{
			throw (e);
		}
	}
	for (unsigned int i = 0; i < new_array.size(); i++)
		this->_arr[i] = new_array._arr[i];
	return (*this);
} 

template <typename T>
T	&Array<T>::operator[](std::size_t idx)
{
	if (idx < 0 || idx >= this->size())
		throw (Array::ArrayException());
	else
		return (this->_arr[idx]);
}

template <typename T>
const T	&Array<T>::operator[](std::size_t idx) const
{
	if (idx < 0 || idx >= this->size())
		throw (Array::ArrayException());
	else
		return (this->_arr[idx]);
}

template <typename T>
const char	*Array<T>::ArrayException::what() const throw()
{
	return ("the index is out of bounds.");
}

template <typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> &in)
{
	out << "Array size: " << in.size() << ", Array value: ";
	for (unsigned int i = 0; i < in.size(); i++)
	{
		out << in[i];
		if (i < in.size() - 1)
			out << ", ";
	}
	return (out);
}
