#ifndef SET_HPP
#define SET_HPP

#include "./set/set_RB_tree.hpp"
#include "./set/set_rb_tree_iterator.hpp"
#include "./vector/reverse_iterator.hpp"
#include "./vector/lexicographical_compare.hpp"
#include "./vector/equal.hpp"
#include "vector.hpp"

namespace ft
{

template < typename T, typename Compare = less<T>, typename Alloc = std::allocator<T> >
class set
{
private:
	Compare									_comp;
	Alloc									_allocation;
	set_RB_tree<T, Compare, Alloc>			_rb_tree;

public:
	// MEMBER TYPES
	typedef T																			key_type;
	typedef T																			value_type;
	typedef	std::size_t																	size_type;
	typedef	std::ptrdiff_t																difference_type;
	typedef	Compare																		key_compare;
	typedef Compare																		value_compare;
	typedef	Alloc																		allocator_type;
	typedef	typename allocator_type::reference											reference;
	typedef	typename allocator_type::const_reference									const_reference;
	typedef	typename allocator_type::pointer											pointer;
	typedef	typename allocator_type::const_pointer										const_pointer;
	typedef ft::set_rb_tree_iterator< const value_type, ft::set_Node<value_type> >		iterator;
	/* As for the standard associative containers, this in the standard section § 23.2.4:
	iterator of an associative container is of the bidirectional iterator category. 
	For associative containers where the value type is the same as the key type, 
	both iterator and const_iterator are constant iterators. It is unspecified whether 
	or not iterator and const_iterator are the same type. */
	typedef ft::set_rb_tree_iterator< const value_type, ft::set_Node<value_type> >		const_iterator;
	typedef ft::reverse_iterator<iterator>												reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;

  /* __  __ _____ __  __ ____  _____ ____    _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
    |  \/  | ____|  \/  | __ )| ____|  _ \  |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
    | |\/| |  _| | |\/| |  _ \|  _| | |_) | | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
    | |  | | |___| |  | | |_) | |___|  _ <  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
    |_|  |_|_____|_|  |_|____/|_____|_| \_\ |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ */

	//CONSTRUCTORS//
	explicit set( const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()): _comp(comp), _allocation(alloc)
	{
		//nothing here
	}

	template <class InputIterator>
	set( InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()): _comp(comp), _allocation(alloc)
	{
		insert(first, last);
	}

	set( const set & src ): _comp(src._comp), _allocation(src._allocation)
	{
		insert(src.begin(), src.end());
	}

	//DESTRUCTORS//
	~set( void )
	{
		// nothing here
	}

	//OPERATOR OVERLOAD//
	set &			operator=( const set & rhs )
	{
		if (this != &rhs)
		{
			this->clear();
			_rb_tree.reassign_root();
			insert(rhs.begin(), rhs.end());
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
		return iterator(_rb_tree.begin());
	}

	const_iterator	begin( void ) const
	{
		return const_iterator(_rb_tree.begin());
	}

	iterator		end( void )
	{
		return iterator(_rb_tree.end());
	}

	const_iterator	end( void ) const
	{
		return const_iterator(_rb_tree.end());
	}

	reverse_iterator		rbegin( void )
	{
		return reverse_iterator(_rb_tree.end());
	}

	const_reverse_iterator	rbegin( void ) const
	{
		return const_reverse_iterator(_rb_tree.end());
	}

	reverse_iterator		rend( void )
	{
		return reverse_iterator(_rb_tree.begin());
	}

	const_reverse_iterator		rend( void ) const
	{
		return const_reverse_iterator(_rb_tree.begin());
	}

  /*  ____    _    ____   _    ____ ___ _______   __
	 / ___|  / \  |  _ \ / \  / ___|_ _|_   _\ \ / /
	| |     / _ \ | |_) / _ \| |    | |  | |  \ V / 
	| |___ / ___ \|  __/ ___ \ |___ | |  | |   | |  
	 \____/_/   \_\_| /_/   \_\____|___| |_|   |_|  */

	bool				empty( void ) const
	{
		if (_rb_tree.get_Size() == 0)
			return true;
		return false;
	}

	size_type			size( void ) const
	{
		return _rb_tree.get_Size();
	}

	size_type			max_size( void ) const
	{
		return _rb_tree.get_Max_Size();
	}

  /* __  __  ___  ____ ___ _____ ___ _____ ____  ____  
	|  \/  |/ _ \|  _ \_ _|  ___|_ _| ____|  _ \/ ___| 
	| |\/| | | | | | | | || |_   | ||  _| | |_) \___ \ 
	| |  | | |_| | |_| | ||  _|  | || |___|  _ < ___) |
	|_|  |_|\___/|____/___|_|   |___|_____|_| \_\____/ */

	pair<iterator, bool>	insert( const value_type & val)
	{
		return _rb_tree.insert(val);
	}

	iterator				insert( iterator pos, const value_type & val)
	{
		(void)pos;
		return insert(val).first;
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
		_rb_tree.erase(*pos);
	}

	size_type				erase( const key_type & k )
	{
		if (count(k))
		{
			_rb_tree.erase(k);
			return 1;
		}
		return 0;
	}

	void					erase( iterator first, iterator last)
	{
		ft::vector<key_type>	it_vec(iter_distance(first, last));
		iterator				temp(first);

		while (temp != last)
		{
			it_vec.push_back(*temp);
			temp++;
		}
		for (size_t i = 0; i < it_vec.size(); i++)
			_rb_tree.erase(it_vec[i]);
	}

	void					swap( set & x)
	{
		_rb_tree.swap(x._rb_tree);
	}

	void					clear( void )
	{
		_rb_tree.clear();
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
		return value_compare();
	}

/*	  ___  ____  _____ ____      _  _____ ___ ___  _   _ ____  
	 / _ \|  _ \| ____|  _ \    / \|_   _|_ _/ _ \| \ | / ___| 
	| | | | |_) |  _| | |_) |  / _ \ | |  | | | | |  \| \___ \ 
	| |_| |  __/| |___|  _ <  / ___ \| |  | | |_| | |\  |___) |
	 \___/|_|   |_____|_| \_\/_/   \_\_| |___\___/|_| \_|____/ */

	 iterator				find( const key_type & k)
	 {
		 return iterator(_rb_tree.search_tree(k));
	 }

	 const_iterator			find( const key_type & k) const
	 {
		 return const_iterator(_rb_tree.search_tree(k));
	 }

	 size_type				count( const key_type & k) const
	 {
		 if (find(k) == this->end())
		 {
			 return 0;
		 }
		 return 1;
	 }

	 iterator				lower_bound( const key_type & k)
	 {
		return iterator(_rb_tree.lower_bound(k));
	 }

	 const_iterator			lower_bound( const key_type & k) const
	 {
		 return const_iterator(_rb_tree.lower_bound(k));
	 }

	 iterator				upper_bound( const key_type & k)
	 {
		return iterator(_rb_tree.upper_bound(k));
	 }

	 const_iterator			upper_bound( const key_type & k) const
	 {
		return const_iterator(_rb_tree.upper_bound(k));
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

	//  void					print_tree( void )
	//  {
	// 	 _rb_tree.print_tree();
	//  }


}; // end of set class

template < class T, class Compare, class Alloc>
bool		operator==( const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template < class T, class Compare, class Alloc>
bool		operator!=( const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs)
{
	return (!(lhs == rhs));
}

template < class T, class Compare, class Alloc>
bool		operator<( const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template < class T, class Compare, class Alloc>
bool		operator<=( const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs)
{
	return (!(rhs < lhs));
}

template < class T, class Compare, class Alloc>
bool		operator>( const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs)
{
	return (rhs < lhs);
}

template < class T, class Compare, class Alloc>
bool		operator>=( const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs)
{
	return (!(lhs < rhs));
}


}; // end of namespace


#endif
