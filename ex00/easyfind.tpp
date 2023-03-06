/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:22:36 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/06 16:02:31 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "easyfind.hpp"
# include "NotFoundException.hpp"

template<typename T>
void easyfind(T container, int value) throw(NotFoundException){
	if (has_iterator<T>::has)
	{
		typedef typename T::iterator ft_it;
		for (ft_it it = container.begin(); it != container.end(); it++)
		{
			if (*it == value)
			{
				std::cout << "Found value ["<< *it <<"]" << std::endl;
				return;
			}
		}
		throw NotFoundException();
	}
	else
	{
		std::cerr << "Provided type has no iterator." << std::endl;
	}
}
