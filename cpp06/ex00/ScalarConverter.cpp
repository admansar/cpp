/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 08:56:57 by admansar          #+#    #+#             */
/*   Updated: 2023/09/18 08:59:24 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

void converter(double d, std::string type)
{
	int i;

	i = static_cast<int>(d);
	if (type == "int" || type  == "char")
	{
		if (type == "char")
		{
			if (i >= 32 && i <= 126)
				std::cout << "char: '" << static_cast<char>(i)  << "'\n";
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(d) << ".0f\n";
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if (type == "float")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::convert (std::string av)
{
	double				d;
	char				*endptr;
	std::istringstream	is(av);
	std::string			type;

	d = std::strtod (av.c_str(), &endptr);
	if (endptr != av.c_str())
	{
		if (*endptr == 'f')
			type = "float";
		else if (d - static_cast<int>(d) == 0)
		{
			int i = static_cast<int>(d);
			long int li = static_cast<long int>(d);
			if (i <= CHAR_MAX && i >= CHAR_MIN)
				type = "char";
			else if (li <= INT_MAX && li >= INT_MIN)
				type = "int";
		}
		else
			type = "double";
	}
	else
		throw "failed to convert";
	if (is)
	{
		if (type != "float")
			is >> d;
		converter(d, type);
	}
	else
		throw "failed to convert";
}

ScalarConverter::~ScalarConverter()
{}
