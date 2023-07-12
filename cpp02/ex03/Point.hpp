/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:58:26 by admansar          #+#    #+#             */
/*   Updated: 2023/07/10 18:58:27 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private :
		Fixed const x;
		Fixed const y;
	public :
		Point();
		Point(float const xf, float const yf);
		Point(Point const &other);
		Point& operator=(const Point &other);
		Fixed determinant(Point const b, Point const point) const;
		Fixed get_x() const;
		Fixed get_y() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& output, const Point &other);

#endif


