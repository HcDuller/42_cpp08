/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:51:29 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/08 16:39:39 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include "Span.hpp"

std::vector<int>* fixedSizeVector(std::size_t size){
	std::vector<int>* ptr = new std::vector<int>(size);
	ptr->reserve(size);
	return (ptr);
};
std::vector<int>* newIfValid(Span const& origin){
	if (origin.thereIsContent())
		return (fixedSizeVector(origin.getCapacity()));
	return (NULL);
}

Span::Span():_content(NULL),_size(0){};
Span::Span(const unsigned int size):_content(fixedSizeVector(size)),_size(0){};
Span::Span(Span const& origin):_content(newIfValid(origin)),_size(origin._size){};
Span::~Span(){
	if (this->thereIsContent()){
		delete this->_content;
	}
};
Span& Span::operator=(Span const& rhe) throw(std::overflow_error){
	if (this->getCapacity() > rhe.getCapacity())
	{
		this->_content->erase(this->_content->begin(),this->_content->end());
		for (std::vector<int>::iterator it = rhe._content->begin();it != rhe._content->end(); it++ ){
			this->_content->push_back(*it);
		}
		this->_size = rhe._size;
		return (*this);
	}
	else
		throw std::overflow_error("Source Span is bigger then dest Span.");
};
bool Span::thereIsContent() const{
	if (this->_content != NULL)
		return (true);
	return (false);
};
std::size_t Span::getCapacity() const{
	if (this->thereIsContent())
		return (this->_content->capacity());
	return (0);
};
std::size_t Span::getFilled() const{
	return (this->_size);
};
void Span::addNumber(const int& n) throw(std::overflow_error){
	if (this->thereIsContent())
	{
		if (this->getFilled() < this->getCapacity()){
			this->_content->at(this->_size) = n;
			this->_size += 1;
			return;
		}
		throw std::overflow_error("The Span object cannot hold more numbers.");
		return;
	}
	throw std::overflow_error("Span Object has no internal storage.");
};
void Span::fillSpan(iterator begin, iterator& end){
	static bool seedIsSet = false;
	if (!seedIsSet)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		seedIsSet = true;
	}
	std::generate(begin, end, std::rand);
}
Span::iterator Span::getBegin(){
	return (this->_content->begin());
}
Span::iterator Span::getEnd(){
	return (this->_content->end());
}
int Span::shortestSpan(){
	int span = __INT_MAX__;
	std::sort(this->getBegin(), this->getEnd(), std::less<int>());
	Span::iterator end = this->getEnd();
	if(this->getBegin() != --(this->getEnd())){
		for (Span::iterator begin = this->getBegin(); begin < --end; begin++){
			if ((*(begin + 1) - *begin) < span)
				span = (*(begin + 1) - *begin);
		}
		return (span);
	}
	return (0);
};
int Span::longestSpan(){
	std::sort(this->getBegin(), this->getEnd(), std::less<int>());
	std::vector<int>::iterator begin = this->getBegin();
	std::vector<int>::iterator end = this->getEnd();
	end--;
	return (*end - *begin);
};
void Span::printContent(std::size_t n){
	iterator it = this->getBegin();
	iterator end = this->getEnd();
	while (it != end && n > 0){
		std::cout << *it << std::endl;
		it++;
		n--;
	}
};