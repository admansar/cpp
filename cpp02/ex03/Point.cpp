/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:58:21 by admansar          #+#    #+#             */
/*   Updated: 2023/07/10 18:58:23 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point()
	:x(0) ,y(0)
{}

Point::Point(float const xf, float const yf)
	:x(xf) ,y(yf)
{}

Point::Point(Point const &other)
	:x(other.x), y(other.y)
{}

Point& Point::operator=(const Point &other)
{
	return (*this);
}

Point::~Point()
{}

Fixed Point::determinant(Point const b, Point const point) const
{
	Fixed delta;

	delta = ((b.x - point.x) * (this->y - point.y)) - ((b.y - point.y) * (this->x - point.x));
		return (delta);
}

Fixed Point::get_x() const
{
	return (x);
}

Fixed Point::get_y() const
{
	return (y);
}

std::ostream& operator<<(std::ostream& output, const Point &a)
{
	output << " (" << a.get_x() << ',' << a.get_y() << ") ";
	return (output);
}
