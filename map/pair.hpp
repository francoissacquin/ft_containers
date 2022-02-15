#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace ft
{

template <class T1, class T2>
struct pair
{

	typedef T1		first_type;
	typedef T2		second_type;

	first_type		_first;
	second_type		_second;

	//CONSTRUCTORS//
	pair(): _first(), _second()
	{
		// nothing here
	}

	pair( const T1 & x, const T2 & y): _first(x), _second(y)
	{
		// nothing here
	}

	template< class U1, class U2 >
	pair( const pair<U1, U2> & p ): _first(p._first), _second(p._second)
	{
		// nothing here
	}

	//ASSIGNATION OPERATOR//
	pair &		operator=( const pair & other )
	{
		if (this != &other)
		{
			_first = other._first;
			_second =other._second;
		}
		return *this;
	}

}; // end of struct pair

//MAKE PAIR
template < class T1, class T2 >
ft::pair<T1, T2>		make_pair( T1 x, T2 y )
{
	return pair<T1, T2>(x, y);
}

// RELATIONAL OPERATORS
template < class T1, class T2 >
bool					operator==( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	if (lhs._first == rhs._first && lhs._second == rhs._second)
		return true;
	return false;
}

template < class T1, class T2 >
bool					operator!=( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return (!(lhs == rhs));
}

template < class T1, class T2 >
bool					operator<( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return lhs._first < rhs._first || (!(rhs._first < lhs._first) && lhs._second < rhs._second);
}

template < class T1, class T2 >
bool					operator<=( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return (!(rhs < lhs));
}

template < class T1, class T2 >
bool					operator>( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return (rhs < lhs);
}

template < class T1, class T2 >
bool					operator>=( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return (!(lhs < rhs));
}

template < class T1, class T2 >
std::ostream &			operator<<( std::ostream & o, const ft::pair<T1, T2>& rhs)
{
	o << rhs._first << "|-|" << rhs._second;
	return o;
}

} // end of namespace

#endif
