/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:59:45 by admansar          #+#    #+#             */
/*   Updated: 2023/09/22 15:59:47 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_hpp
#define easyfind_hpp

#include <iostream>
#include <algorithm>
#include <vector>


template <typename T>
bool easyfind (T container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) != container.end())
		return (std::cout << to_find << " is in" << std::endl, 0);
	else
		return (std::cerr << to_find << " is not in" << std::endl, 1);
}

#endif
