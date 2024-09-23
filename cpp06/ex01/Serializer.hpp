/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:18:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/09/23 10:56:22 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

typedef struct s_data
{
	int	data;
}	t_data;


class Serializer
{
	public:
		~Serializer();
		static uintptr_t	serialize(t_data *ptr);
		static t_data			*deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &new_serializer);
		Serializer	&operator=(const Serializer &new_serializer);
};


#endif