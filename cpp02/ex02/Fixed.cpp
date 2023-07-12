#include "Fixed.hpp"

Fixed::Fixed(int i)
	:nombre_en_virgule_fix(roundf(i * pow(2, bits)))
{}

Fixed::Fixed(float f)
	:nombre_en_virgule_fix(roundf(f * pow(2, bits)))
{}

void Fixed::set(int s)
{
	this->nombre_en_virgule_fix = s;
}

int Fixed::get() const
{
	return (nombre_en_virgule_fix / pow (2, bits));
}

Fixed::Fixed()
: nombre_en_virgule_fix(0)
{}

Fixed::Fixed(const Fixed &other)
{
	this->nombre_en_virgule_fix = other.nombre_en_virgule_fix;
}

Fixed::~Fixed(){}

int Fixed::toInt() const
{
	return ((int)nombre_en_virgule_fix / pow(2, bits));
}

float Fixed::toFloat() const
{
	return ((float)nombre_en_virgule_fix / pow(2, bits));
}

						/*operators*/

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->nombre_en_virgule_fix = other.nombre_en_virgule_fix;
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other)
{
	return ((Fixed((this->nombre_en_virgule_fix + other.nombre_en_virgule_fix) / pow (2, bits))));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed re;

	re = (this->nombre_en_virgule_fix - other.nombre_en_virgule_fix) / pow (2, bits);
	return (re);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed re;

	re.nombre_en_virgule_fix = other.nombre_en_virgule_fix * this->nombre_en_virgule_fix / pow (2, bits);
	return (re);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed re;

	re.nombre_en_virgule_fix = other.nombre_en_virgule_fix / this->nombre_en_virgule_fix * pow (2, bits);
	return (re);
}

Fixed& Fixed::operator++()
{
	nombre_en_virgule_fix++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed re;
	re.nombre_en_virgule_fix = this->nombre_en_virgule_fix;
	nombre_en_virgule_fix++;
	return (re);
}

Fixed& Fixed::operator--()
{
	nombre_en_virgule_fix--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed re;
	re.nombre_en_virgule_fix = this->nombre_en_virgule_fix;
	nombre_en_virgule_fix--;
	return (re);
}

bool Fixed::operator>(Fixed& other) const
{	
	return (this->nombre_en_virgule_fix > other.nombre_en_virgule_fix);
}

bool Fixed::operator<(Fixed& other) const
{	
	return (this->nombre_en_virgule_fix < other.nombre_en_virgule_fix);
}

bool Fixed::operator>=(Fixed& other) const
{	
	return (this->nombre_en_virgule_fix >= other.nombre_en_virgule_fix);
}

bool Fixed::operator<=(Fixed& other) const
{	
	return (this->nombre_en_virgule_fix <= other.nombre_en_virgule_fix);
}

bool Fixed::operator==(Fixed& other) const
{	
	return (this->nombre_en_virgule_fix == other.nombre_en_virgule_fix);
}

bool Fixed::operator!=(Fixed& other) const
{	
	return (this->nombre_en_virgule_fix != other.nombre_en_virgule_fix);
}
					/*min_max*/

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.nombre_en_virgule_fix >= b.nombre_en_virgule_fix)
        return a;
    return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.nombre_en_virgule_fix >= b.nombre_en_virgule_fix)
        return a;
    return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.nombre_en_virgule_fix <= b.nombre_en_virgule_fix)
        return a;
    return b;
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.nombre_en_virgule_fix <= b.nombre_en_virgule_fix)
        return a;
    return b;
}

Fixed Fixed::min(Fixed a, Fixed b)
{
	if (a.nombre_en_virgule_fix <= b.nombre_en_virgule_fix)
		return (a);
	return (b);
}

