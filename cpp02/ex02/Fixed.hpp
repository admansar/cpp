#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int nombre_en_virgule_fix;
		static const int  bits = 8;
	public :
		Fixed();
		Fixed(int i);
		Fixed(float f);
		Fixed(const Fixed &other);
		void set(int s);
		int get() const;
		Fixed& operator=(const Fixed& other);
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		bool operator<=(Fixed& other) const;
		bool operator>=(Fixed& other) const;
		bool operator<(Fixed& other) const;
		bool operator>(Fixed& other) const;
		bool operator==(Fixed& other) const;
		bool operator!=(Fixed& other) const;
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed min(Fixed a, Fixed b);
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
};

int pow(int nbr, int pow);
std::ostream& operator<<(std::ostream& out, const Fixed& fix_num);

#endif
