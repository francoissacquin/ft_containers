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

}; // end of struct pair

} // end of namespace

#endif
