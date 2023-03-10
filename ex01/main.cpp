/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:10:45 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/10 18:06:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <iomanip>

#define GREEN "\033[32;1m"
#define RESET "\033[0m"
#define WHITE "\033[37;1m"
#define RED "\033[31;1m"

int main(void){
	std::cout << GREEN << "Small Span - test and addNumber + overflow" << RESET << std::endl;
	try{
		Span mySpan(10);
		std::cout << WHITE << "Adding number: ";
		for (unsigned int i = 0; i < mySpan.getCapacity() - 1; i++){
			std::cout << i*100 << "...";
			mySpan.addNumber(static_cast<int>(i*100));
		}
		std::cout << 15;
		mySpan.addNumber(15);
		std::cout << RESET << std::endl;
		//mySpan.printContent(10); //uncomment this to print contents of mySpan
		std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
		mySpan.addNumber(10);
	}catch(std::exception& e){
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Huge Span - test iterator set" << RESET << std::endl;
	try{
		Span mySpan(10000);
		Span::iterator begin = mySpan.getBegin();
		Span::iterator end = mySpan.getEnd();
		std::cout << std::boolalpha << "begin < end : [" << (begin < end) << "]" << std::endl;
		mySpan.fillSpan(mySpan.getBegin(), end);
		//mySpan.printContent(15); //uncomment this to print contents of mySpan
		std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
		begin = mySpan.getBegin();
		end = mySpan.getEnd();
		std::cout << std::boolalpha << "begin < end : [" << (begin < end) << "]" << std::endl;

	}catch(std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}