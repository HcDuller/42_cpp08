/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:32:13 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/06 15:10:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "NotFoundException.hpp"

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