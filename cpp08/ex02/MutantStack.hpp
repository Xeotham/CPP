/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:00:23 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/01 08:49:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &new_stack);
		~MutantStack();
	public:
		typedef typename Container::iterator iterator;
		iterator	begin();
		iterator	end();
	public:
		MutantStack	&operator=(MutantStack &new_stack);
	
};

#include "MutantStack.tpp"

#endif