/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:32:13 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/10 14:48:53 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "NotFoundException.hpp"

# define GREEN "\033[32;1m"
# define RESET "\033[0m"
# define BLUE "\033[33;1m"
# define RED "\033[31;1m"

template<typename T>
struct has_iterator{
	typedef char yes[1];
	typedef char no[2];

	template<typename Y>
	static yes& test(typename Y::iterator* it);

	template<typename>
	static no& test(...);
	static const bool has = sizeof(test<T>(0)) == sizeof(yes);
};

template<typename T>
void easyfind(T container, int value) throw(NotFoundException);
#include "easyfind.tpp"