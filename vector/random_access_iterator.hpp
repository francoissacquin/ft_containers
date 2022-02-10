#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

// https://fr.fr1lib.org/book/465615/0af8bd
// C++ Programming Language, 3rd Edition
// Chapter 16 : Standard Containers

#include "iterator.hpp"

namespace ft
{

template < typename T >
class random_access_iterator: iterator < random_access_iterator_tag, T >
{
protected:
	T*		_ptr;

public:

	typedef	typename	iterator<random_access_iterator_tag, T>::value_type			value_type;
	typedef				ptrdiff_t													difference_type;
	typedef				T*															pointer;
	typedef				T&															reference;
	typedef	typename	iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	
	//For all operations and function definitions, refer to https://www.cplusplus.com/reference/iterator/
	//CONSTRUCTORS
	random_access_iterator( void ): _ptr()
	{
		//nothing here
	}

	random_access_iterator( pointer	ptr): _ptr(ptr)
	{
		//nothing here
	}

	random_access_iterator( const random_access_iterator & src ): _ptr(src._ptr)
	{
		//nothing here
	}

	//DESTRUCTORS
	~random_access_iterator( void )
	{
		//nothing here
	}

	//CONVERSION TO CONST ITERATOR ALLOWED
	operator random_access_iterator<const T> () const
	{
		return random_access_iterator<const T>(_ptr);
	}

	//ASSIGNATION OPERATION OVERLOAD
	random_access_iterator &	operator=( const random_access_iterator & rhs )
	{
		if (this != &rhs)
		{
			_ptr = rhs.base();
		}
		return *this;
	}

	//INCREMENTATION
	random_access_iterator &	operator++( void )
	{
		_ptr++;
		return *this;
	}

	random_access_iterator		operator++( int )
	{
		random_access_iterator copy(*this);

		_ptr++;
		return copy;
	}

	//DEREFERENCED AS AN RVALUE (see also https://en.cppreference.com/w/cpp/language/operator_member_access)
	reference					operator*( void ) const
	{
		return *_ptr;
	}

	pointer						operator->( void ) const
	{
		return _ptr;
	}

	//DECREMENTATION
	random_access_iterator &	operator--( void )
	{
		this->_ptr--;
		return *this;
	}

	random_access_iterator		operator--( int )
	{
		random_access_iterator copy(*this);

		this->_ptr--;
		return copy;
	}

	//ARITHMETIC OPERATORS + and -
	// for these implementation see https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#_ZNKSt13move_iteratorplENSt15iterator_traitsIT_E15difference_typeE
	// on line 1080 and line 833
	// or this https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#__gnu_cxx::__normal_iterator
	// on line 833
	random_access_iterator		operator+( difference_type n ) const
	{
		random_access_iterator temp(_ptr + n);
		return temp;
	}

	random_access_iterator		operator-( difference_type n ) const
	{
		random_access_iterator temp(_ptr - n);
		return temp;
	}

	//COMPOUND ASSIGNEMENT OPERATIONS
	random_access_iterator		operator+=( difference_type n )
	{
		_ptr += n;
		return *this;
	}

	random_access_iterator		operator-=( difference_type n )
	{
		_ptr -= n;
		return *this;
	}

	//OFFSET DEREFERENCE OFFSET OPERATOR
	reference		operator[]( difference_type n )
	{
		return *(_ptr + n);
	}

	//BASE FUNCTION FOR NON-MEMBER FUNCTIONS TO GET ACCESS TO _ptr
	T*			base( void ) const
	{
		return _ptr;
	}
};

// NON-MEMBER EQUALITY/INEQUALITY COMPARISONS AND FUNCTIONS
template<typename T>
bool				operator==( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs )
{
	return (lhs.base() == rhs.base());
}

//POLYMORPHISM FRO ITERATOR VS CONST ITERATOR COMPARISONS
template<typename T_lhs, typename T_rhs>
bool				operator==( const random_access_iterator<T_lhs> & lhs, const random_access_iterator<T_rhs> & rhs )
{
	return (lhs.base() == rhs.base());
}

template<typename T>
bool				operator!=( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs )
{
	return (lhs.base() != rhs.base());
}

template<typename T_lhs, typename T_rhs>
bool				operator!=( const random_access_iterator<T_lhs> & lhs, const random_access_iterator<T_rhs> & rhs )
{
	return (lhs.base() != rhs.base());
}

template<typename T>
bool				operator<( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) 
{
	return (lhs.base() < rhs.base());
}

template<typename T_lhs, typename T_rhs>
bool				operator<( const random_access_iterator<T_lhs> & lhs, const random_access_iterator<T_rhs> & rhs )
{
	return (lhs.base() < rhs.base());
}

template<typename T>
bool				operator<=( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs )
{
	return (lhs.base() <= rhs.base());
}

template<typename T_lhs, typename T_rhs>
bool				operator<=( const random_access_iterator<T_lhs> & lhs, const random_access_iterator<T_rhs> & rhs )
{
	return (lhs.base() <= rhs.base());
}

template<typename T>
bool				operator>( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs )
{
	return (lhs.base() > rhs.base());
}

template<typename T_lhs, typename T_rhs>
bool				operator>( const random_access_iterator<T_lhs> & lhs, const random_access_iterator<T_rhs> & rhs )
{
	return (lhs.base() > rhs.base());
}

template<typename T>
bool				operator>=( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs )
{
	return (lhs.base() >= rhs.base());
}

template<typename T_lhs, typename T_rhs>
bool				operator>=( const random_access_iterator<T_lhs> & lhs, const random_access_iterator<T_rhs> & rhs )
{
	return (lhs.base() >= rhs.base());
}

// Operation overloads for additions and substractions
template <typename T>
random_access_iterator<T>		operator+( typename random_access_iterator<T>::difference_type n, typename ft::random_access_iterator<T> & rhs )
{
	return (rhs + n);
}

template <typename T>
typename random_access_iterator<T>::difference_type		operator-( const random_access_iterator<T> lhs, const random_access_iterator<T> rhs )
{
	return (lhs.base() - rhs.base());
}

template <typename T_lhs, typename T_rhs>
typename random_access_iterator<T_lhs>::difference_type		operator-( const random_access_iterator<T_lhs> lhs, const random_access_iterator<T_rhs> rhs )
{
	return (lhs.base() - rhs.base());
}

// FUNCTION THAT REIMPLEMENTS STD::DISTANCE() FOR THE VECTOR MEMBER TYPES FUNCTIONS WHO USE RANDOM_ACCESS_ITERATORS
template <class InputIterator>
size_t		iter_distance(InputIterator first, InputIterator last)
{
	size_t		i = 0;

	while (first != last)
	{
		first++;
		i++;
	}
	return i;
}

}; // end of namespace ft


#endif
