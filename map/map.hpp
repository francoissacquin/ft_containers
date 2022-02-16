#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <stdexcept>
#include "./map/RB_tree.hpp"

namespace ft
{

template < typename Key, typename T, typename Compare = less<Key>, typename Alloc = std::allocator < pair < const Key, T > > >
class map
{
private:
	Alloc								_allocation;
	key_compare							_comparison;
	RB_tree<Key, T, Compare, Alloc>		_rb_tree;
	//size_type							_size; // is _size necessary?

public:
	//MEMBER TYPES
	typedef	Key											key_type;
	typedef	T											mapped_type;
	typedef	pair<const key_type, mapped_type>			value_type;
	typedef	std::size_t									size_type;
	typedef	std::ptrdiff_t								difference_type;
	typedef	Compare										key_compare;
	typedef	Alloc										allocator_type;
	typedef	typename allocator_type::reference			reference;
	typedef	typename allocator_type::const_reference	const_reference;
	typedef	typename allocator_type::pointer			pointer;
	typedef	typename allocator_type::const_pointer		const_pointer;
	// bidirectional iterator
	// const bidirectional iterator
	// reverse_iterator
	// const reverse iterator


  /* __  __ _____ __  __ ____  _____ ____    _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
    |  \/  | ____|  \/  | __ )| ____|  _ \  |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
    | |\/| |  _| | |\/| |  _ \|  _| | |_) | | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
    | |  | | |___| |  | | |_) | |___|  _ <  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
    |_|  |_|_____|_|  |_|____/|_____|_| \_\ |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ */

	//CONSTRUCTORS//
	explicit map( const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()): _comparison(comp), _allocation(alloc)
	{
		//nothing here
	}

	template <class InputIterator>
	map( InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()): _comparison(comp), _allocation(alloc)
	{
		insert(first, last);
	}

	map( const map & src ): _comparison(src._comparison)
	{
		_tree = src._tree;
	}

	//DESTRUCTORS//
	~map( void )
	{
		// nothing here
	}

	//OPERATOR OVERLOAD//
	map &			operator=( const map & rhs )
	{
		if (this != &rhs)
		{
			_tree = rhs._tree;
		}
		return *this;
	}


  /* ___ _____ _____ ____      _  _____ ___  ____  ____  
	|_ _|_   _| ____|  _ \    / \|_   _/ _ \|  _ \/ ___| 
	 | |  | | |  _| | |_) |  / _ \ | || | | | |_) \___ \ 
	 | |  | | | |___|  _ <  / ___ \| || |_| |  _ < ___) |
	|___| |_| |_____|_| \_\/_/   \_\_| \___/|_| \_\____/ */

	iterator		begin( void )
	{
		//nothing here;
	}

	const_iterator	begin( void )
	{
		//nothing here
	}


}; //end of map class




};// end of namespace

#endif
