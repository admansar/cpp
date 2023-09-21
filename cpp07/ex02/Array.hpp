#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private :
		T				*elem;
		unsigned int	n;
	public :
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array& operator=(Array<T> const &other);
		T& operator[] (unsigned int in);
		unsigned int size();
		class OutOfLength;
		~Array();
};

template <typename T>
class Array<T>::OutOfLength: public std::exception
{
	public :
		const char *what() const throw();
};

template <typename T>
Array<T>::Array()
	: elem(NULL), n (0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	: elem (new T[n]()), n (n)
{}

template <typename T>
Array<T>::Array(Array<T> const &other)
	: elem (NULL), n (0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator= (Array const &other)
{
	unsigned int i;

	if (this->n)
		delete[] this->elem;
	this->n = other.n;
	this->elem = new T[this->n]();
	i = 0;
	while (i < other.n)
	{
		this->elem[i] = other.elem[i];
		i++;
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[] (unsigned int n)
{
	if (n >= this->n || n < 0)
		throw Array::OutOfLength();
	return (this->elem [n]);
}

template <typename T>
const char *Array<T>::OutOfLength::what() const throw()
{
	return ("out of range !");
}

template <typename T>
unsigned int Array<T>::size()
{
	return (n);
}

template <typename T>
Array<T>::~Array()
{
	if (n)
		delete[] this->elem;
}
#endif


