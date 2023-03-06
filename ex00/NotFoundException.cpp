/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotFoundException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:12:14 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/06 15:13:25 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotFoundException.hpp"

const char* NotFoundException::what() const throw(){
	return ("Value not found.");
}