/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:41:43 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/07 02:27:10 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stdexcept>

class Span
{
private:
	std::vector<int>* _content;
	std::size_t _size;
	Span();
public:
	void addNumber(const int& n) throw(std::overflow_error);
	bool thereIsContent() const;
	std::size_t getCapacity() const;
	std::size_t getFilled() const;
	Span(const unsigned int size);
	Span(Span const& origin);
	Span& operator=(Span const& rhe) throw(std::overflow_error);
	~Span();
};