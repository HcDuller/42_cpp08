/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:22:36 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/03 19:47:20 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "easyfind.hpp"

template<typename T>
void easyfind(T container, int value){
	if (has_iterator<T>::has)
	{
		typedef typename T::iterator ft_it;
		std::cout << "Provided type has iterators." << std::endl;
		for (ft_it it = container.begin(); it != container.end(); it++)
		{
			if (*it == value)
			{
				std::cout << "Found value ["<< *it <<"]" << std::endl;
				return;
			}
		}
		std::cout << "Couldn't find value [" << value << "]" << std::endl;
	}
	else
	{
		std::cerr << "Provided type has no iterator." << std::endl;
	}
}
