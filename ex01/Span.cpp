/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:51:29 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/07 02:34:14 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include <vector>
#include "Span.hpp"

std::vector<int>* fixedSizeVector(std::size_t size){
	std::vector<int>* ptr = new std::vector<int>(0);
	ptr->reserve(size);
	return (ptr);
};
std::vector<int>* newIfValid(Span const& origin){
	if (origin.thereIsContent())
		return (new std::vector<int>(origin.getCapacity()));
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
			this->_content->push_back(n);
			this->_size += 1;
			return;
		}
		throw std::overflow_error("The Span object cannot hold more numbers.");
		return;
	}
	throw std::overflow_error("Span Object has no internal storage.");
};
