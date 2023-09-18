/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:41:06 by admansar          #+#    #+#             */
/*   Updated: 2023/09/18 11:41:07 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &other)
{
	(void)other;
}

Serializer Serializer::operator= (Serializer const &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t re;

	re = reinterpret_cast<uintptr_t>(ptr);
	return (re);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *re;

	re = reinterpret_cast<Data *>(raw);
	return (re);
}


Serializer::~Serializer()
{}


