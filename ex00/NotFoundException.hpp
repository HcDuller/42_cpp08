/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotFoundException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:09:44 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/10 20:10:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

class NotFoundException : public std::exception{
	public:
		NotFoundException();
		NotFoundException(const NotFoundException& origin);
		NotFoundException& operator=(const NotFoundException& origin);
		~NotFoundException() throw();
		virtual const char* what() const throw();
};