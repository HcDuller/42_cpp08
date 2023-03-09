/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:47:48 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/09 15:36:25 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <list>
#include "MutantStack.hpp"

void subjectMainStack(void){
	std::cout << BLUE << "################# MUTANTSTACK START #################" << RESET << std::endl;
	MutantStack<int>
	mstack;
	std::cout << GREEN << "Push: 100" << std::endl;
	mstack.push(100);
	std::cout << GREEN << "Push: 50" << std::endl;
	mstack.push(50);
	std::cout << WHITE << "Top:  " << mstack.top() << std::endl;
	std::cout << RED << "Pop() (50)" << std::endl;
	mstack.pop();
	std::cout << RESET << "Size: " << mstack.size() << std::endl;
	std::cout << GREEN << "Push: 40" << std::endl;
	mstack.push(40);
	std::cout << GREEN << "Push: 30" << std::endl;
	mstack.push(30);
	std::cout << GREEN << "Push: 20" << std::endl;
	mstack.push(20);
	std::cout << GREEN << "Push: 0" << RESET << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "Content of iterator (begin): " << GREEN << *it << RESET << std::endl;
	std::cout << "Move iterator with ++." << std::endl;
	++it;
	std::cout << "Content of iterator : " << GREEN << *it << RESET << std::endl;
	std::cout << "Move iterator with --." << std::endl;
	--it;
	std::cout << "Content of iterator : " << GREEN << *it << RESET << std::endl;
	std::cout << RESET;
	std::cout << "Top [0], Bottom [" << (ite- it) << "]" <<std::endl;
	for (int index = 0; index < (ite - it); index++){
		std::cout << "Pos [" << index << "] Value[" << GREEN << *(it + index) << RESET << "]" << std::endl;
	}
	std::stack<int> cpyMutant(mstack);
	std::cout << BLUE << "################# MUTANTSTACK END #################" << RESET << std::endl;
}
void subjectMainList(void){
	std::cout << YELLOW << "################# LIST START #################" << RESET << std::endl;
	std::list<int>
	mstack;
	std::cout << GREEN << "Push: 100" << std::endl;
	mstack.push_back(100);
	std::cout << GREEN << "Push: 50" << std::endl;
	mstack.push_back(50);
	std::cout << WHITE << "Top:  " << mstack.back() << std::endl;
	std::cout << RED << "Pop() (50)" << std::endl;
	mstack.pop_back();
	std::cout << RESET << "Size: " << mstack.size() << std::endl;
	std::cout << GREEN << "Push: 40" << std::endl;
	mstack.push_back(40);
	std::cout << GREEN << "Push: 30" << std::endl;
	mstack.push_back(30);
	std::cout << GREEN << "Push: 20" << std::endl;
	mstack.push_back(20);
	std::cout << GREEN << "Push: 0" << RESET << std::endl;
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator it_mut = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	std::cout << "Content of iterator (begin): " << GREEN << *it << RESET << std::endl;
	std::cout << "Move iterator with ++." << std::endl;
	++it;
	std::cout << "Content of iterator : " << GREEN << *it << RESET << std::endl;
	std::cout << "Move iterator with --." << std::endl;
	--it;
	std::cout << "Content of iterator : " << GREEN << *it << RESET << std::endl;
	std::cout << RESET;
	std::cout << "Top [0], Bottom [5]" <<std::endl;
	int index = 0;
	while (it_mut != ite)
	{
		//std::cout << *it_mut << std::endl;
		std::cout << "Pos [" << index << "] Value[" << GREEN << *it_mut << RESET << "]" << std::endl;
		++it_mut;
		++index;
	}
	// for (int index = 0; index < (ite - it); index++){
	// 	std::cout << "Pos [" << index << "] Value[" << *(it + index) << "]" << std::endl;
	// }
	std::list<int> cpyMutant(mstack);
	std::cout << YELLOW << "################# LIST END #################" << RESET << std::endl;
}


int main(void){
	subjectMainStack();
	subjectMainList();
	return (0);
}