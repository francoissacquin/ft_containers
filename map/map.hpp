#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <stdexcept>
#include "RB_tree.hpp"
#include "bidirectional_iterator.hpp"

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
	typedef	Key																key_type;
	typedef	T																mapped_type;
	typedef	pair<const key_type, mapped_type>								value_type;
	typedef	std::size_t														size_type;
	typedef	std::ptrdiff_t													difference_type;
	typedef	Compare															key_compare;
	typedef	Alloc															allocator_type;
	typedef	typename allocator_type::reference								reference;
	typedef	typename allocator_type::const_reference						const_reference;
	typedef	typename allocator_type::pointer								pointer;
	typedef	typename allocator_type::const_pointer							const_pointer;
	typedef ft::rb_tree_iterator< value_type, ft::Node<value_type> >		iterator;
	typedef ft::rb_tree_iterator< const value_type, ft::Node<value_type> >	const_iterator;
	typedef ft::reverse_iterator<iterator>									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
	


	// Nested class of value compare that we can use and return in value_compare member function
	class value_compare: public binary_function<value_type, value_type, bool>
	{
		friend class map;

		protected:
		key_compare			_comp;
		
		value_compare(key_compare c): _comp(c)
		{
			// nothing here
		}

		public:

		typedef bool			result_type;
		typedef value_type		first_type;
		typedef	value_type		second_type;

		bool		operator() (const value_type & x, const value_type & y) const
		{
			return _comp(x._first, y._first);
		}
	}; 


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
		_tree.clear();
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
		return iterator(_tree.begin());
	}

	const_iterator	begin( void ) const
	{
		return const_iterator(_tree.begin());
	}

	iterator		end( void )
	{
		return iterator(_tree.end());
	}

	const_iterator	end( void ) const
	{
		return const_iterator(_tree.end());
	}

	reverse_iterator		rbegin( void )
	{
		return reverse_iterator(_tree.end());
	}

	const_reverse_iterator	rbegin( void ) const
	{
		return const_reverse_iterator(_tree.end());
	}

	reverse_iterator		rend( void )
	{
		return reverse_iterator(_tree.begin());
	}

	const_reverse_iterator		rend( void ) const
	{
		return const_reverse_iterator(_tree.begin());
	}


  /*  ____    _    ____   _    ____ ___ _______   __
	 / ___|  / \  |  _ \ / \  / ___|_ _|_   _\ \ / /
	| |     / _ \ | |_) / _ \| |    | |  | |  \ V / 
	| |___ / ___ \|  __/ ___ \ |___ | |  | |   | |  
	 \____/_/   \_\_| /_/   \_\____|___| |_|   |_|  */

	bool				empty( void ) const
	{
		if (_tree.get_Size() == 0)
			return true;
		return false;
	}

	size_type			size( void ) const
	{
		return _tree.get_Size();
	}

	size_type			max_size( void ) const
	{
		return _tree.get_Max_Size();
	}


  /* _____ _     _____ __  __ _____ _   _ _____      _    ____ ____ _____ ____ ____  
	| ____| |   | ____|  \/  | ____| \ | |_   _|    / \  / ___/ ___| ____/ ___/ ___| 
	|  _| | |   |  _| | |\/| |  _| |  \| | | |     / _ \| |  | |   |  _| \___ \___ \ 
	| |___| |___| |___| |  | | |___| |\  | | |    / ___ \ |__| |___| |___ ___) |__) |
	|_____|_____|_____|_|  |_|_____|_| \_| |_|   /_/   \_\____\____|_____|____/____/  */

	mapped_type &		operator[](const key_type & k)
	{
		return insert(value_type(k, mapped_type()))._first->_second;
	}


  /* __  __  ___  ____ ___ _____ ___ _____ ____  ____  
	|  \/  |/ _ \|  _ \_ _|  ___|_ _| ____|  _ \/ ___| 
	| |\/| | | | | | | | || |_   | ||  _| | |_) \___ \ 
	| |  | | |_| | |_| | ||  _|  | || |___|  _ < ___) |
	|_|  |_|\___/|____/___|_|   |___|_____|_| \_\____/ */

	pair<iterator, bool>	insert( const value_type & val)
	{
		return _tree.insert(val);
	}

	iterator				insert( iterator pos, const value_type & val)
	{
		(void)pos;
		return insert(val)._first;
	}

	template <class InputIterator>
	void					insert( InputIterator first, InputIterator last )
	{
		while (first != last)
		{
			insert(*first);
			first++;
		}
	}

	void					erase( iterator pos)
	{
		_tree.erase(pos._first);
	}

	size_type				erase( const key_type & k )
	{
		if (count(k))
		{
			_tree.erase(k);
			return 1;
		}
		return 0;
	}

	void					erase( iterator first, iterator last)
	{
		ft::vector<key_type>	it_vec(iterator_len(first, last));
		iterator				temp(first);

		while (temp != last)
		{
			it_vec.push_back(temp->_first);
			temp++;
		}
		for (size_t i = 0; i < it_vec.size(); i++)
			_tree.erase(it_vec[i]);
	}

	void					swap( map & x)
	{
		_tree.swap(_tree);
	}

	void					clear( void )
	{
		_tree.clear();
	}

/*	  ___  ____ ____  _____ ______     _______ ____  ____  
	 / _ \| __ ) ___|| ____|  _ \ \   / / ____|  _ \/ ___| 
	| | | |  _ \___ \|  _| | |_) \ \ / /|  _| | |_) \___ \ 
	| |_| | |_) |__) | |___|  _ < \ V / | |___|  _ < ___) |
	 \___/|____/____/|_____|_| \_\ \_/  |_____|_| \_\____/ */

	key_compare				key_comp() const
	{
		return key_compare();
	}

	value_compare			value_comp() const
	{
		return value_compare(key_compare());
	}

/*	  ___  ____  _____ ____      _  _____ ___ ___  _   _ ____  
	 / _ \|  _ \| ____|  _ \    / \|_   _|_ _/ _ \| \ | / ___| 
	| | | | |_) |  _| | |_) |  / _ \ | |  | | | | |  \| \___ \ 
	| |_| |  __/| |___|  _ <  / ___ \| |  | | |_| | |\  |___) |
	 \___/|_|   |_____|_| \_\/_/   \_\_| |___\___/|_| \_|____/ */

	 iterator				find( const key_type & k)
	 {
		 return iterator(_tree.search_tree(k));
	 }

	 const_iterator			find( const key_type & k) const
	 {
		 return const_iterator(_tree.search_tree(k));
	 }

	 size_type				count( const key_type & k) const
	 {
		 iterator		it(_tree.search_tree(k));

		 if (it == end())
		 {
			 return 0;
		 }
		 return 1;
	 }

	 iterator				lower_bound( const key_type & k)
	 {
		return iterator(_tree.bounded_search_tree(k));
	 }

	 const_iterator			lower_bound( const key_type & k)
	 {
		 return const_iterator(_tree.bounded_search_tree(k));
	 }

	 iterator				upper_bound( const key_type & k)
	 {
		iterator		it(_tree.bounded_search_tree(k));

		if (!(_comp(it->data->_first, k)) && !(_comp(k, it->data->_first)))
			return ++it;
		else
			return it;
	 }

	 const_iterator			upper_bound( const key_type & k) const
	 {
		iterator		it(_tree.bounded_search_tree(k));

		if (!(_comp(it->data->_first, k)) && !(_comp(k, it->data->_first)))
			return const_iterator(++it);
		else
			return const_iterator(it);
	 }

	 pair<iterator, iterator>		equal_range( const key_type & k)
	 {
		 pair<iterator, iterator>		ret;

		 ret.first = lower_bound(k);
		 ret.second = upper_bound(k);
		 return ret;
	 }

	 pair<const_iterator, const_iterator>		equal_range( const key_type & k) const
	 {
		 pair<const_iterator, const_iterator>		ret;

		 ret.first = lower_bound(k);
		 ret.second = upper_bound(k);
		 return ret;
	 }

	 allocator_type			get_allocator( void ) const
	 {
		 return _allocation;
	 }

}; //end of map class

template < class Key, class T, class Compare, class Alloc>
bool		operator==( const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template < class Key, class T, class Compare, class Alloc>
bool		operator!=( const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (!(lhs == rhs));
}

template < class Key, class T, class Compare, class Alloc>
bool		operator<( const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template < class Key, class T, class Compare, class Alloc>
bool		operator( const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}


};// end of namespace

#endif
