/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:31:40 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/06 15:59:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "NotFoundException.hpp"
#include <vector>
#include <iostream>

int main(void){
	std::vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);
	myVector.push_back(6);
	try{
		easyfind(myVector, 3);
		easyfind(myVector, 4);
		easyfind(myVector, 5);
		easyfind(myVector, 6);
		easyfind(myVector, 7);
	}catch(NotFoundException& e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}