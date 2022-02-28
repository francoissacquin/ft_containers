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

	first_type		first;
	second_type		second;

	//CONSTRUCTORS//
	pair(): first(), second()
	{
		// nothing here
	}

	pair( const T1 & x, const T2 & y): first(x), second(y)
	{
		// nothing here
	}

	template< class U1, class U2 >
	pair( const pair<U1, U2> & p ): first(p.first), second(p.second)
	{
		// nothing here
	}

	//ASSIGNATION OPERATOR//
	pair &		operator=( const pair & other )
	{
		if (this != &other)
		{
			first = other.first;
			second = other.second;
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
	if (lhs.first == rhs.first && lhs.second == rhs.second)
		return true;
	return false;
}

// template < class T1, class T2 >
// bool					operator==( ft::pair<T1, T2> & lhs, ft::pair<T1, T2> & rhs)
// {
// 	if (lhs.first == rhs.first && lhs.second == rhs.second)
// 		return true;
// 	return false;
// }

template < class T1, class T2 >
bool					operator!=( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return (!(lhs == rhs));
}

template < class T1, class T2 >
bool					operator<( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
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
	o << rhs.first << "|" << rhs.second;
	return o;
}

} // end of namespace

#endif
