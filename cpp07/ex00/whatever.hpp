/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:05:28 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/24 08:24:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif