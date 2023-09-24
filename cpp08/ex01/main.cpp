/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:51:06 by admansar          #+#    #+#             */
/*   Updated: 2023/09/22 21:00:00 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main()
{
	Span sp = Span(5);
	std::vector <int> v;
	int a[] = {6, 3 ,17 ,9 ,11};
	int i = 0;
	while (i < 5)
		v.push_back(a[i++]);

	sp.addNumbers(v.begin(), v.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

//int main() {
//    try {
//        Span span(10000); // Initialize a Span with a maximum capacity of 10,000
//
//        for (int i = 0; i < 10000; ++i) {
//            span.addNumber(i);
//        }
//
//        int shortest = span.shortestSpan();
//        int longest = span.longestSpan();
//
//        std::cout << "Shortest Span: " << shortest << std::endl;
//        std::cout << "Longest Span: " << longest << std::endl;
//    } catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
