#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft
{

// Template parameters are : T (element type) and Allocator (for memory allocation)
template < typename T, typename Alloc = std::allocator<T> >
class vector
{
private:
	value_type		*_array;
	size_type		_size;
	size_type		_max_size;
	allocator_type	_allocation;
	size_type		_capacity;

public:
	//MEMBER TYPES
	typedef T								value_type;
	typedef Alloc							allocator_type;
	typedef std::size_t						size_type;
	typedef std::ptrdiff_t					difference_type;
	typedef value_type &					reference;
	typedef const value_type &				const_reference;
	typedef allocator_type::pointer			pointer;
	typedef allocator_type::const_pointer	const_pointer;
	//faut que je vois plus tard pour faire les iterateurs
	// comme ca on 		iterator
	//					const_iterator
	//					reverse_iterator
	//					const_reverse_iterator


  /* __  __ _____ __  __ ____  _____ ____    _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
    |  \/  | ____|  \/  | __ )| ____|  _ \  |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
    | |\/| |  _| | |\/| |  _ \|  _| | |_) | | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
    | |  | | |___| |  | | |_) | |___|  _ <  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
    |_|  |_|_____|_|  |_|____/|_____|_| \_\ |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ */
	

	//CONSTRUCTORS//
	explicit vector( const allocator_type & alloc = allocator_type()): _array(NULL), _size(0), _max_size(alloc.max_size()), _allocation(alloc), _capacity(0)
	{
		_array = _allocation.allocate(0);
	}

	explicit vector( size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()): _size(n), _max_size(alloc.max_size()), _allocation(alloc), _capacity(n)
	{
		_array = _allocation.allocate(n);
		for (size_type i = 0; i < n; i++)
		{
			_allocation.construct(_array + i, val);
		}
	}

	template <class InputIterator>
	vector( InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()): _max_size(alloc.max_size()), _allocation(alloc)
	{
		// I need to write the iterator before doing that
		// DO STUFF WITH ITERATORS HERE
	}

	vector( const vector & src ): _size(src._size), _max_size(src._max_size), _capacity(src._capacity)
	{
		_array = _allocation.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
		{
			_allocation.construct(_array + i, src[i]);
		}
	}

	//DESTRUCTORS//
	~vector( void )
	{
		clear();
	}

	//OPERATOR OVERLOAD//
	vector &				operator=( const vector & rhs )
	{
		if (this != &rhs)
		{
			clear();
			_size = rhs._size;
			_capacity = rhs._capacity;
			_array = _allocation.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocation.construct(_array + i, rhs[i]);
		}
		return *this;
	}

  /* ___ _____ _____ ____      _  _____ ___  ____  ____  
	|_ _|_   _| ____|  _ \    / \|_   _/ _ \|  _ \/ ___| 
	 | |  | | |  _| | |_) |  / _ \ | || | | | |_) \___ \ 
	 | |  | | | |___|  _ <  / ___ \| || |_| |  _ < ___) |
	|___| |_| |_____|_| \_\/_/   \_\_| \___/|_| \_\____/ */

	iterator				begin( void )
	{
		return iterator(_array);
	}
	/*=========================================*/
	const_iterator			begin( void ) const
	{
		return const_iterator(_array);
	}
	/*=========================================*/
	iterator				end( void )
	{
		return iterator(_array + _size);
	}
	/*=========================================*/
	const_iterator			end( void ) const
	{
		return const_iterator(_array + _size);
	}
	/*=========================================*/
	reverse_iterator		rbegin( void )
	{
		return reverse_iterator(end());
	}
	/*=========================================*/
	const_reverse_iterator	rbegin( void ) const
	{
		return const_reverse_iterator(end());
	}
	/*=========================================*/
	reverse_iterator		rend( void )
	{
		return reverse_iterator(begin());
	}
	/*=========================================*/
	const_reverse_iterator	rend( void ) const
	{
		return const_reverse_iterator(begin());
	}


  /*  ____    _    ____   _    ____ ___ _______   __
	 / ___|  / \  |  _ \ / \  / ___|_ _|_   _\ \ / /
	| |     / _ \ | |_) / _ \| |    | |  | |  \ V / 
	| |___ / ___ \|  __/ ___ \ |___ | |  | |   | |  
	 \____/_/   \_\_| /_/   \_\____|___| |_|   |_|  */

	size_type				size( void ) const
	{
		return _size;
	}

	size_type				max_size( void ) const
	{
		return _max_size;
	}

	void					resize( size_type n, value_type value = value_type())
	{
		if (n < _size)
		{
			for (size_type i = 0; i < _size - n; i++)
				_allocation.destroy(_array + (_size - i));
			_size = _size - (_size - n);
		}
		else if (n > _size && n <= _capacity)
		{
			for (size_type i = 0; i < n - _size; i++)
				_allocation.construct(_array + (_size + i), value);
			_size = n;
		}
		else if (n > _capacity)
		{
			reserve(n);
			for (size_type i = _size; i < n; i++)
				_allocation.construct(_array + i, value);
		}
	}

	size_type				capacity( void ) const
	{
		return _capacity;
	}

	bool					empty( void ) const
	{
		if (_size == 0)
			return true;
		return false;
	}

	void					reserve( size_type n )
	{
		if (n > _capacity)
		{
			if (n > _max_size)
				throw std::length_error();
			vector<value_type> copy(*this);
			clear();
			_size = n;
			_max_size = alloc.max_size();
			_capacity = n;
			_array = _allocation.allocate(n);
			for (size_type i = 0; i < copy._size; i++)
			{
				_allocation.construct(_array + i, copy[i]);
			}
			copy.clear();
		}
	}


  /* _____ _     _____ __  __ _____ _   _ _____      _    ____ ____ _____ ____ ____  
	| ____| |   | ____|  \/  | ____| \ | |_   _|    / \  / ___/ ___| ____/ ___/ ___| 
	|  _| | |   |  _| | |\/| |  _| |  \| | | |     / _ \| |  | |   |  _| \___ \___ \ 
	| |___| |___| |___| |  | | |___| |\  | | |    / ___ \ |__| |___| |___ ___) |__) |
	|_____|_____|_____|_|  |_|_____|_| \_| |_|   /_/   \_\____\____|_____|____/____/  */

	reference				operator[]( size_type pos )
	{
		return _array[pos];
	}

	const_reference			operator[]( size_type pos ) const
	{
		return _array[pos];
	}

	reference				at( size_type pos)
	{
		if (!(pos < size))
			throw std::out_of_range("vector");
		return _array[pos];
	}

	const_reference			at( size_type pos ) const
	{
		if (!(pos < size))
			throw std::out_of_range("vector");
		return _array[pos];
	}

	reference				front( void )
	{
		// return *begin();
		return _array[0];
	}

	const_reference			front( void ) const
	{
		// return *begin();
		return _array[0];
	}

	reference				back( void )
	{
		// return *(end() - 1);
		return _array[_size - 1];
	}

	const_reference			back( void ) const
	{
		// return *(end() - 1);
		return _array[_size - 1];
	}


  /* __  __  ___  ____ ___ _____ ___ _____ ____  ____  
	|  \/  |/ _ \|  _ \_ _|  ___|_ _| ____|  _ \/ ___| 
	| |\/| | | | | | | | || |_   | ||  _| | |_) \___ \ 
	| |  | | |_| | |_| | ||  _|  | || |___|  _ < ___) |
	|_|  |_|\___/|____/___|_|   |___|_____|_| \_\____/ */

	void					assign( size_type n, const value_type & value)
	{
		if (n == 0)
			return ;
		if (n > _capacity)
		{
			clear();
			_size = n;
			_capacity = n;
			_array = _allocation.allocate(_capacity);
			for (size_type i = 0; i < n; i++)
				_allocation.construct(_array + i, value);
		}
		else
		{
			for (size_type i = 0; i < _size; i++)
				_allocation.destroy(_array + i);
			_size = n;
			for (size_type i = 0; i < _size; i++)
				_allocation.construct(_array + i, value);
		}
	}

	template <class InputIt>
	void					assign( InputIt first, InputIt last )
	{
		// DO STUFF HERE WITH ITERATORS
	}

	void					push_back( const value_type & value ) // TESTER L'INVALIDATION DES ITERATEURS PAR UN RESIZE * 2
	{
		if (_size == 0)
			reserve(1);
		else if (_size == _capacity)
			reserve(_size * 2);
		_allocation.construct(_array + _size, value);
		_size = _size + 1;
		
	}

	void					pop_back( void )
	{
		if (this.empty())
			return;
		_allocation.destroy(_array + _size - 1);
		_size = _size - 1;
	}

	iterator				insert( iterator pos, const value_type & value)
	{
		// DO STUFF HERE WITH ITERATORS
	}

	iterator				insert( const_iterator pos, size_type count, const value_type & & value )
	{
		// DO STUFF HERE WITH ITERATORS
	}

	template <class InputIt>
	void					insert( iterator pos, InputIt first, InputIt last )
	{
		// DO STUFF HERE WITH ITERATORS
	}

	iterator				erase( iterator pos )
	{
		// DO STUFF HERE WITH ITERATORS
	}

	iterator				erase( iterator first, iterator last )
	{
		// DO STUFF HERE WITH ITERATORS
	}

	void					swap( vector & other )
	{
		value_type		*copy_array;
		size_type		copy_size;
		size_type		copy_max_size;
		allocator_type	copy_allocation;
		size_type		copy_capacity;

		copy_array = _array;
		copy_size = _size;
		copy_max_size = _max_size;
		copy_allocation = _allocation;
		copy_capacity = _capacity;

		_array = other._array;
		_size = other._size;
		_max_size = other._max_size;
		_allocation = other._allocation;
		_capacity = other._capacity;

		other._array = copy_array;
		other._size = copy_size;
		other._max_size = copy_max_size;
		other._allocation = copy_allocation;
		other._capacity = copy_capacity;
	}

	void					clear( void )
	{
		for (size_t i = 0; i < _size; i++)
			_allocation.destroy(_array + i);
		_allocation.deallocate(_array, _capacity);
		_array = NULL;
		_size = 0;
		_capacity = 0;
	}

 /*     _    _     _     ___   ____    _  _____ ___  ____  
	   / \  | |   | |   / _ \ / ___|  / \|_   _/ _ \|  _ \ 
	  / _ \ | |   | |  | | | | |     / _ \ | || | | | |_) |
	 / ___ \| |___| |__| |_| | |___ / ___ \| || |_| |  _ < 
	/_/   \_\_____|_____\___/ \____/_/   \_\_| \___/|_| \_\ */

	allocator_type			get_allocator( void ) const
	{
		std::allocator<value_type>	copy(_allocation);
		return copy;
	}

};// end of vector class


 /*  _   _  ___  _   _       __  __ _____ __  __ ____  _____ ____    _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
	| \ | |/ _ \| \ | |     |  \/  | ____|  \/  | __ )| ____|  _ \  |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
	|  \| | | | |  \| |_____| |\/| |  _| | |\/| |  _ \|  _| | |_) | | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
	| |\  | |_| | |\  |_____| |  | | |___| |  | | |_) | |___|  _ <  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
	|_| \_|\___/|_| \_|     |_|  |_|_____|_|  |_|____/|_____|_| \_\ |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ */

template <class T, class Alloc>
bool		operator==( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs )
{
	if (lhs._size == rhs._size)
	{
		// possibility of replacing that by std::equal(lhs.begin(), lhs.end(), rhs.begin())
		for (size_type i = 0; i < lhs._size; i++)
		{
			if (lhs._array[i] != rhs._array[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

template <class T, class Alloc>
bool		operator!=( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs )
{
	if (lhs == rhs)
		return false;
	return true;
}

template <class T, class Alloc>
bool		operator<( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs )
{
	//possibility of replacing by std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
	size_type	i = 0;

	while (i < lhs._size)
	{
		if (i == rhs._size || rhs._array[i] < lhs._array[i])
			return false;
		else if (lhs._array[i] < rhs._array[i])
			return true;
		i++;
	}
	return (i != rhs._size);
}

template <class T, class Alloc>
bool		operator<=( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs )
{
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool		operator>( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs )
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool		operator>=( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs )
{
	return !(lhs < rhs);
}

template <class T, class Alloc>
void		swap( vector<T, Alloc> & lhs, vector<T, Alloc> & rhs )
{
	lhs.swap(rhs);
}

}; //end of namespace

#endif
