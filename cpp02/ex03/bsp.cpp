/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:58:31 by admansar          #+#    #+#             */
/*   Updated: 2023/07/10 18:58:33 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed null(0);
	Fixed E1(a.determinant(b, point));
	Fixed E2(b.determinant(c, point));
	Fixed E3(c.determinant(a, point));

	if ((E1 > null  && E2 > null && E3 > null) || (E1 < null  && E2 < null && E3 < null))
		return (true);
	return (false);
}
