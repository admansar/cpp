/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:16:43 by admansar          #+#    #+#             */
/*   Updated: 2023/07/10 18:57:10 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int pow(int nbr, int pow)
{
    int i;
    int nb;

    if (!pow)
     return (1);
    nb = nbr;
    i = 0;
    while (++i < pow)
        nbr *= nb;
    return (nbr);
}

int main(void) 
{
	Point a(3, 5);
	Point b(11, 5);
	Point c(7.1, 9);
	Point point(8, 8);

	if (bsp(a, b, c, point))
		std::cout << point << "est a l'interieur de triangle definie par" << a << "et" << b << "et" << c << std::endl;
	else
		std::cout << point << "est a l'exterieur de triangle definie par" << a << "et" << b << "et" << c << std::endl;
	return (0);
}
