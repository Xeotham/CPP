/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:25:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/27 15:12:59 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T list, int value)
{
	typename T::iterator	found;

	found = std::find(list.begin(), list.end(), value);
	if (found == list.end() && *list.end() != value)
		std::cerr << "There is no " << value << " in the container." << std::endl;
	else
		std::cout << "The value " << *found << " was found." << std::endl;
	return (found);
}
