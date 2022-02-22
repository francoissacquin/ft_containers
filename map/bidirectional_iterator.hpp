#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include "../vector/iterator.hpp"
#include "RB_tree.hpp"

namespace ft
{

	template < typename T, typename node >
	class rb_tree_iterator: iterator < bidirectional_iterator_tag, T >
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

		rb_tree_iterator( void ): _ptr()
		{
			// nothing here
		}

		rb_tree_iterator( node * ptr ): _ptr(ptr)
		{
			// nothing here
		}

		rb_tree_iterator( const rb_tree_iterator & src ): _ptr(src._ptr)
		{
			// nothing here
		}

		~rb_tree_iterator( void )
		{
			// nothing here
		}

		//CONVERSION TO CONST ITERATOR ALLOWED
		operator rb_tree_iterator<const T, node>() const
		{
			return (rb_tree_iterator<const T, node>(_ptr));
		}

		//ASSIGNATION OPERATION OVERLOAD
		rb_tree_iterator &		operator=(const rb_tree_iterator & rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		//INCREMENTATION
		rb_tree_iterator &		operator++( void )
		{
			_ptr = successor(_ptr);
			return *this;
		}

		rb_tree_iterator		operator++( int )
		{
			rb_tree_iterator	copy(*this);

			_ptr = sucessor(_ptr);
			return copy;
		}

		//DECREMENTATION
		rb_tree_iterator &		operator--( void )
		{
			_ptr = predecessor(_ptr);
			return *this;
		}

		rb_tree_iterator		operator--( int )
		{
			rb_tree_iterator	copy(*this);

			_ptr = predecessor(_ptr);
			return copy;
		}

		//DEREFERENCED AS AN RVALUE 
		reference				operator*( void ) const
		{
			return *_ptr;
		}

		pointer					operator->( void ) const
		{
			return _ptr;
		}

		// COMPARISON OPERATORS
		bool					operator==( const rb_tree_iterator & rhs)
		{
			return (_ptr == rhs._ptr);
		}

		bool					operator!=( const rb_tree_iterator & rhs)
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
