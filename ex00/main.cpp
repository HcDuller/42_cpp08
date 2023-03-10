/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:31:40 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/10 14:49:31 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "NotFoundException.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

void printValue(const int& v){
	std::cout << v << "... ";
};
int main(void){
	std::vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);
	myVector.push_back(6);
	std::cout << "Contents:" << std::endl;
	std::for_each(myVector.begin(), myVector.end(), printValue);
	std::cout << std::endl;
	try{
		easyfind(myVector, 3);
		easyfind(myVector, 4);
		easyfind(myVector, 5);
		easyfind(myVector, 6);
		easyfind(myVector, 7);
	}catch(NotFoundException& e){
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}