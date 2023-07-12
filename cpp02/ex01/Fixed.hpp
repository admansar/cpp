/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:16:53 by admansar          #+#    #+#             */
/*   Updated: 2023/07/08 22:16:54 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int nombre_en_virgule_fix;
		static const int  bits = 8;
	public :
		Fixed();
		Fixed(int i);
		Fixed(float f);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();

};

int pow(int nbr, int pow);
std::ostream& operator<<(std::ostream& out, const Fixed& fix_num);

#endif
