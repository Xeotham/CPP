/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:06:21 by mhaouas           #+#    #+#             */
/*   Updated: 2024/10/01 08:49:46 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &new_stack) : std::stack<T, Container>(new_stack)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template<typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(MutantStack<T, Container> &new_stack)
{
	if (this != &new_stack)
		this->c = new_stack.c;
	return (*this);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}
