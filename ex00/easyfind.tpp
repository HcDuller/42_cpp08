/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:22:36 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/10 14:48:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "easyfind.hpp"
# include "NotFoundException.hpp"
# include <algorithm>



template<typename T>
void easyfind(T container, int value) throw(NotFoundException){
	std::cout << "trying to find " << BLUE << value << RESET << "...";
	if (has_iterator<T>::has)
	{
		typedef typename T::iterator ft_it;
		ft_it found_element = std::find(container.begin(), container.end(), value);
		if (found_element != container.end())
		{
			std::cout << "Found value ["<< GREEN << *found_element << RESET <<"]" << std::endl;
			return;
		}
		throw NotFoundException();
	}
	else
	{
		std::cerr << RED << "Provided type has no iterator." << RESET << std::endl;
	}
}
