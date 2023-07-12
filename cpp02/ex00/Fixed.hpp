/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:17:41 by admansar          #+#    #+#             */
/*   Updated: 2023/07/08 22:17:43 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int nbr_virgule_fixe;
		static const int nbr_de_bit = 8;
	public :
		Fixed();
		Fixed(Fixed &constracteur_par_copie);
		Fixed& operator=(Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

#endif
