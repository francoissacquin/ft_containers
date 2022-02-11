#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <class T1, class T2>
struct pair
{
private:
	T1		_first;
	T2		_second;

public:
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

	T1			get_first( void ) //is this needed?
	{
		return _first;
	}

	T2			get_second( void ) // is this needed?
	{
		return _second;
	}

}; // end of struct pair

//MAKE PAIR
template < class T1, class T2 >
ft::pair<T1, T2>		make_pair( T1 t, T2 u )
{
	return pair<T1, T2>(t, u);
}

// RELATIONAL OPERATORS
template < class T1, class T2 >
bool					operator==( const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
{
	if (lhs.get_first() == rhs.get_first() && lhs.get_second() == rhs.get_second())
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
	if (!(lhs.get_first() < rhs.get_first()))
		return (lhs.get_second() < rhs.get_second());
	return (lhs.get_first() < rhs.get_first())
}

} // end of namespace

#endif
