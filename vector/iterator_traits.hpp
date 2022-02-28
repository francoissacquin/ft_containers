#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include "iterator.hpp"

namespace ft
{

// classic iterator structure that will serve as interface for the
// iterator attributes and allow us to retrieve iterator attributes
// for any container.
// see also : https://en.cppreference.com/w/cpp/iterator/iterator_traits
template < class iterator >
struct iterator_traits
{
	typedef typename iterator::difference_type		difference_type;
	typedef typename iterator::value_type			value_type;
	typedef typename iterator::pointer				pointer;
	typedef typename iterator::reference				reference;
	typedef typename iterator::iterator_category		iterator_category;
};

// Specialization in order to use iterator operations on raw pointers
template < class T >
struct iterator_traits< T* >
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef random_access_iterator_tag		iterator_category;
};

// Specialization in order to use iterator operations on const raw pointers
template < class T >
struct iterator_traits < const T* >
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef random_access_iterator_tag		iterator_category;
};

} // end of namespace ft

#endif
