/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:55:23 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/30 13:10:54 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	public:
		Span();
		Span(const Span &new_span);
		Span(const unsigned int N);
		~Span();
	public:
		const Span	&operator=(const Span &new_span);
	public:
		std::vector<int>::iterator	getBegin();
		std::vector<int>::iterator	getEnd();
		void				addNumber(int nb);
		void				addNumber(std::vector<int>::iterator start, int size);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
	private:
		unsigned int		_size;
		unsigned int		_max_value;
		std::vector<int>	_storage;
	private:
		static int	generateRandom();
	private:
		class	SpanException : public std::exception
		{
			const char	*what() const throw();
		};
};

#endif