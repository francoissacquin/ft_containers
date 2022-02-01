#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef> // needed for ptrdif_t type definition

// This is just the base iterator template as defined on:
// https://en.cppreference.com/w/cpp/iterator/iterator
// It serves mainly to define required member types for
// iterators of all type (see Category for the different types).

// You can also check out https://www.cplusplus.com/reference/iterator/iterator/

// See also hapters 16 and 17 and 19 of "C++ Programming Language" 3rd edition
// link to the book here : https://fr.fr1lib.org/book/465615/0af8bd

namespace ft
{

template < class Category,
	class T,
	class Distance = std::ptrdiff_t,
	class Pointer = T*,
	class Reference = T& >
struct iterator
{
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

// Defining empty structures for iterator categories tags
// see link here : https://en.cppreference.com/w/cpp/iterator/iterator_tags

struct	input_iterator_tag { };
struct	output_iterator_tag { };
struct	forward_iterator_tag : public input_iterator_tag { };
struct	bidirectional_iterational_tag : public forward_iterator_tag { };
struct	random_access_iterator_tag : public bidirectional_iterational_tag { };

} // end of namespace ft




#endif
