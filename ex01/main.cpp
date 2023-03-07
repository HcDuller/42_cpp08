/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:10:45 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/07 02:19:45 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){
	Span mySpan(3);
	mySpan.addNumber(1);
	mySpan.addNumber(2);
	mySpan.addNumber(3);
	mySpan.addNumber(3);
	return (0);
}