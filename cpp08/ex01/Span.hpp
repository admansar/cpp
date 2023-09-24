/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:51:44 by admansar          #+#    #+#             */
/*   Updated: 2023/09/22 20:51:46 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private :
		std::vector<int>	v;
		unsigned int		n;
		Span();
		unsigned int sorting_helper(std::string type);

	public :
		Span (const unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);

		typedef std::vector<int>::iterator iter;
		void addNumber(unsigned int num);
   		void addNumbers(iter begin, iter end);


		unsigned int shortestSpan();
		unsigned int longestSpan();

		class FullSpan;
		class LessThenTwo;

		~Span();
};

#endif
