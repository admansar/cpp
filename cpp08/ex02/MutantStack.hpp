#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public :
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack &other);

		class Iterator;
		typedef Iterator iterator;

		void push (T in);
		void pop();
		size_t size();
		T top();
		iterator begin();
		iterator end();

		~MutantStack();
};

template <typename T>
class MutantStack<T>::Iterator
{
	private :
		typename std::stack<T>::container_type::iterator iter;
		Iterator();
	public :
		Iterator(const Iterator &other);
		Iterator(typename std::stack<T>::container_type::iterator in);

		Iterator	&operator=(const Iterator &other);
		Iterator 	&operator++();
		Iterator 	&operator--();
		bool		operator!=(const Iterator &other) const;
		bool		operator==(const Iterator &other) const;
		T			&operator*();

		~Iterator();
};

/*************MUTANTSTACK*****************/

	template <typename T>
MutantStack<T>::MutantStack()
{}

	template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	(void)other;
}

	template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
	(void)other;
	return (*this);
}

	template <typename T>
void MutantStack<T>::push(T in)
{
	std::stack<T>::push(in);
}

	template <typename T>
void MutantStack<T>::pop()
{
	std::stack<T>::pop();
}

	template <typename T>
size_t MutantStack<T>::size()
{
	return (std::stack<T>::size());
}

	template <typename T>
T MutantStack<T>::top()
{
	return (std::stack<T>::top());
}

	template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
	return (Iterator(std::stack<T>::c.begin()));
}

	template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end()
{
	return (Iterator(std::stack<T>::c.end()));
}

	template <typename T>
MutantStack<T>::~MutantStack()
{}

/****************Iterator*****************/

	template <typename T>
MutantStack<T>::Iterator::Iterator()
	: iter (0)
{};

	template <typename T>
MutantStack<T>::Iterator::Iterator(const Iterator &other)
	: iter (other.iter)
{}

	template <typename T>
MutantStack<T>::Iterator::Iterator(typename std::stack<T>::container_type::iterator in)
	: iter (in)
{}

	template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator=(const Iterator &other)
{
	iter = other.iter;
	return (*this);
}

	template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++()
{
	++iter;
	return (*this);
}

	template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--()
{
	--iter;
	return (*this);
}

	template <typename T>
bool MutantStack<T>::Iterator::operator!=(const MutantStack::Iterator &other) const
{
	return ((iter != other.iter));
}

	template <typename T>
bool MutantStack<T>::Iterator::operator==(const MutantStack::Iterator &other) const
{
	return ((iter == other.iter));
}

	template <typename T>
T &MutantStack<T>::Iterator::operator*(){

	return (*iter);
}

	template <typename T>
MutantStack<T>::Iterator::~Iterator()
{}

/*****************************************/

#endif
