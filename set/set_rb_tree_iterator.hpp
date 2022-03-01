#ifndef SET_RB_TREE_ITERATOR_HPP
# define SET_RB_TREE_ITERATOR_HPP

#include <iostream>
#include "../vector/iterator.hpp"
#include "../vector/iterator_traits.hpp"
#include "set_RB_tree.hpp"

namespace ft
{

	template < typename T, typename node >
	class set_rb_tree_iterator: iterator < bidirectional_iterator_tag, T >
	{
	protected:
		node *		_ptr;

	public:

		typedef typename		iterator<bidirectional_iterator_tag, T>::value_type			value_type;
		typedef					ptrdiff_t													difference_type;
		typedef					value_type *												pointer;
		typedef					value_type &												reference;
		typedef					value_type const &											const_reference;
		typedef typename		iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;

		set_rb_tree_iterator( void ): _ptr()
		{
			// nothing here
		}

		set_rb_tree_iterator( node * ptr ): _ptr(ptr)
		{
			// nothing here
		}

		set_rb_tree_iterator( const set_rb_tree_iterator & src ): _ptr(src._ptr)
		{
			// nothing here
		}

		template < typename U >
		set_rb_tree_iterator( const set_rb_tree_iterator & h): _ptr(static_cast<node*>(h._ptr))
		{
			// nothing here
		}

		~set_rb_tree_iterator( void )
		{
			// nothing here
		}

		//CONVERSION TO CONST ITERATOR ALLOWED
		operator set_rb_tree_iterator<const T, node>() const
		{
			return (set_rb_tree_iterator<const T, node>(_ptr));
		}

		//ASSIGNATION OPERATION OVERLOAD
		set_rb_tree_iterator &		operator=(const set_rb_tree_iterator & rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		//INCREMENTATION
		set_rb_tree_iterator &		operator++( void )
		{
			_ptr = successor(_ptr);
			return *this;
		}

		set_rb_tree_iterator		operator++( int )
		{
			set_rb_tree_iterator	copy(*this);

			_ptr = successor(_ptr);
			return copy;
		}

		//DECREMENTATION
		set_rb_tree_iterator &		operator--( void )
		{
			_ptr = predecessor(_ptr);
			return *this;
		}

		set_rb_tree_iterator		operator--( int )
		{
			set_rb_tree_iterator	copy(*this);

			_ptr = predecessor(_ptr);
			return copy;
		}

		//DEREFERENCED AS AN RVALUE 
		reference				operator*( void ) const
		{
			//return *static_cast<node*>(_ptr);
			return _ptr->data;
		}

		pointer					operator->( void ) const
		{
			return &(_ptr->data);
			//return &(_ptr->data);
		}

		// COMPARISON OPERATORS
		bool					operator==( const set_rb_tree_iterator & rhs)
		{
			return (_ptr == rhs._ptr);
		}

		bool					operator!=( const set_rb_tree_iterator & rhs)
		{
			return (_ptr != rhs._ptr);
		}

		//BASE FUNCTION FOR NON-MEMBER FUNCTIONS TO GET ACCESS TO _ptr
		pointer					base( void ) const
		{
			return _ptr;
		}
	};

}; // end of namespace ft


#endif
