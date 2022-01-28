#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

// My new sacred text is https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#std::reverse_iterator
// My implementation is a strict adaptation of the reverse_iterator of the orginal stl library

namespace ft
{

template <typename Iterator>
class reverse_iterator
{
protected:
	Iterator	_current;

public:

	typedef Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;

	//CONSTRUCTORS
	reverse_iterator( void ): _current()
	{
		//nothing here
	}

	explicit reverse_iterator( iterator_type x ): _current(x)
	{
		//nothing here
	}

	reverse_iterator( const reverse_iterator & src ): _current(src._current)
	{
		//nothing here
	}

	template<typename Iter>
	reverse_iterator( const reverse_iterator<Iter> & x ): _current(x._current)
	{
		//nothing here
	}

	//DESTRUCTORS
	~reverse_iterator( void )
	{
		//nothing here
	}

	//ASSIGNATION OPERATOR OVERLOAD
	template<typename Iter>
	reverse_iterator	operator=( const reverse_iterator<Iter> & rhs )
	{
		if (this != &rhs)
		{
			_current = rhs._current;
		}
		return *this;
	}

	//DEREFERENCING AS AN RVALUE
	reference		operator*( void ) const
	{
		Iterator	temp = _current;
		return *--tmp;
	}

	pointer			operator->( void ) const
	{
		return &(operator*());
	}

	//INCREMENTATION AND DECREMENTATION OPERATORS
	reverse_iterator &		operator++( void )
	{
		--_current;
		return *this;
	}

	reverse_iterator		operator++( int )
	{
		reverse_iterator	copy(*this);

		--_current;
		return (copy);
	}

	reverse_iterator &		operator--( void )
	{
		++_current;
		return *this;
	}

	reverse_iterator		operator--( int )
	{
		reverse_iterator	copy(*this);

		++_current;
		return (copy);
	}

	//ARITHMETIC OPERATORS
	reverse_iterator		operator+( difference_type n ) const
	{
		reverse_iterator	temp(_current - n);
		return (temp);
	}

	reverse_iterator &		operator+=( difference_type n )
	{
		_current -= n;
		return *this;
	}

	reverse_iterator		operator-( difference_type n ) const
	{
		reverse_iterator	temp(_current + n);
		return (temp);
	}

	reverse_iterator &		operator-=( difference_type n )
	{
		_current += n;
		return *this;
	}

	//OFFSET DEREFERENCE OFFSET OPERATOR
	reference				operator[]( difference_type n ) const
	{
		return *(*this + n);
	}
};

// NON-MEMBER EQUALITY/INEQUALITY COMPARISONS AND FUNCTIONS FOR 2 REVERSE_ITERATORS
template<typename Iterator>
bool			operator==(const reserve_iterator<Iterator> & lhs, const reserve_iterator<Iterator> & lhs)
{
	return (lhs._current == rhs._current);
}

template<typename Iterator>
bool			operator!=(const reserve_iterator<Iterator> & lhs, const reserve_iterator<Iterator> & lhs)
{
	return (lhs._current != rhs._current);
}

template<typename Iterator>
bool			operator<(const reserve_iterator<Iterator> & lhs, const reserve_iterator<Iterator> & lhs)
{
	return (lhs._current < rhs._current);
}

template<typename Iterator>
bool			operator<=(const reserve_iterator<Iterator> & lhs, const reserve_iterator<Iterator> & lhs)
{
	return (lhs._current <= rhs._current);
}

template<typename Iterator>
bool			operator>(const reserve_iterator<Iterator> & lhs, const reserve_iterator<Iterator> & lhs)
{
	return (lhs._current > rhs._current);
}

template<typename Iterator>
bool			operator>=(const reserve_iterator<Iterator> & lhs, const reserve_iterator<Iterator> & lhs)
{
	return (lhs._current >= rhs._current);
}

// NON-MEMBER EQUALITY/INEQUALITY COMPARISONS AND FUNCTIONS FOR A REVERSE_ITERATOR AND A CONST REVERSE ITERATOR
template<typename Iter_lhs, typename Iter_rhs>
bool			operator==(const reverse_iterator<Iter_lhs> & lhs, const reverse_iterator<Iter_rhs> & rhs)
{
	return (lhs._current)
}


} // end of namespace

#endif
