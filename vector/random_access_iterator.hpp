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
private:
	T*		_ptr;

public:

	typedef	typename	iterator<random_access_iterator_tag, T>::value_type			value_type;
	typedef				ptrdiff_t													difference_type;
	typedef				T*															pointer;
	typedef				T&															reference;
	typedef				const T&													const_reference; // do i keep this?
	typedef	typename	iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	
	//CONSTRUCTORS
	random_access_iterator();
	random_access_iterator(pointer ptr);
	random_access_iterator(const random_access_iterator & src);
}


}; // end of namespace


#endif
