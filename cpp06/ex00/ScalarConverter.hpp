/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 08:56:07 by admansar          #+#    #+#             */
/*   Updated: 2023/09/18 08:56:14 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <iostream>
#include <sstream>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
	public :
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter const &other);
		static void convert (std::string av);
};

#endif
