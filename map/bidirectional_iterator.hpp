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

		operator rb_tree_iterator<const T, node>() const
		{
			return (rb_tree_iterator<const T, node>(_ptr));
		}

		rb_tree_iterator &		operator=(const rb_tree_iterator & rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		rb_tree_iterator &		operator++( void )
		{
			if (_ptr->_right != NULL)
			{
				_ptr = 
			}
		}
	}

}


#endif
