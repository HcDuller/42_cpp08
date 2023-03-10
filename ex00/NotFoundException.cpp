/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotFoundException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:12:14 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/10 20:22:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotFoundException.hpp"

const char* NotFoundException::what() const throw(){
	return ("Value not found.");
}

NotFoundException::NotFoundException(){};
NotFoundException::NotFoundException(const NotFoundException& origin): std::exception(origin){};
NotFoundException& NotFoundException::operator=(const NotFoundException& origin){
	(void)origin;	
	return (*this);
};
NotFoundException::~NotFoundException() throw(){};