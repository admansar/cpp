/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:59:43 by admansar          #+#    #+#             */
/*   Updated: 2023/09/22 16:00:06 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(2);

	easyfind(vec, 4);
}
