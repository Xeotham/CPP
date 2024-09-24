/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:35:12 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/24 08:53:31 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename Arr, typename Func>
void	iter(Arr *array, int size, Func function)
{
	for (int i = 0; i < size; i++)
		array[i] = function(array[i]);
}

#endif