#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP


namespace ft
{

// classic iterator structure that will serve as interface for the
// iterator attributes and allow us to retrieve iterator attributes
// for any container.
// see also : https://en.cppreference.com/w/cpp/iterator/iterator_traits
template < class iterator >
struct iterator_traits
{
	typedef iterator::difference_type		difference_type;
	typedef iterator::value_type			value_type;
	typedef iterator::pointer				pointer;
	typedef iterator::reference				reference;
	typedef iterator::iterator_category		iterator;
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

} // end of namespace

#endif
