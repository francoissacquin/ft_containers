#ifndef STACK_HPP
#define STACK_HPP

#include "./vector.hpp"

namespace ft
{

template < class T, class Container = vector<T> >
class stack
{
public:

	typedef T				value_type;
	typedef	Container		container_type;
	typedef size_t			size_type;

  /* __  __ _____ __  __ ____  _____ ____    _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
    |  \/  | ____|  \/  | __ )| ____|  _ \  |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
    | |\/| |  _| | |\/| |  _ \|  _| | |_) | | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
    | |  | | |___| |  | | |_) | |___|  _ <  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
    |_|  |_|_____|_|  |_|____/|_____|_| \_\ |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ */

	explicit stack( const container_type & ctnr = container_type()): _ct(ctnr)
	{
		// nothing here
	}

	bool					empty( void ) const
	{
		return _ct.empty();
	}

	size_type				size( void ) const
	{
		return _ct.size();
	}

	value_type &			top( void )
	{
		return _ct.back();
	}

	const value_type &		top( void ) const
	{
		return _ct.back();
	}

	void					push( const value_type & val)
	{
		_ct.push_back(val);
	}

	void					pop( void )
	{
		_ct.pop_back();
	}


/*   ____  _____ _        _  _____ ___ ___  _   _    _    _        ___  ____  _____ ____      _  _____ ___  ____  ____  
	|  _ \| ____| |      / \|_   _|_ _/ _ \| \ | |  / \  | |      / _ \|  _ \| ____|  _ \    / \|_   _/ _ \|  _ \/ ___| 
	| |_) |  _| | |     / _ \ | |  | | | | |  \| | / _ \ | |     | | | | |_) |  _| | |_) |  / _ \ | || | | | |_) \___ \ 
	|  _ <| |___| |___ / ___ \| |  | | |_| | |\  |/ ___ \| |___  | |_| |  __/| |___|  _ <  / ___ \| || |_| |  _ < ___) |
	|_| \_\_____|_____/_/   \_\_| |___\___/|_| \_/_/   \_\_____|  \___/|_|   |_____|_| \_\/_/   \_\_| \___/|_| \_\____/ */

	template < class T_ro, class Container_ro >
	friend bool		operator==( const stack<T_ro, Container_ro> & lhs, const stack<T_ro, Container_ro> & rhs);

	template < class T_ro, class Container_ro >
	friend bool		operator!=( const stack<T_ro, Container_ro> & lhs, const stack<T_ro, Container_ro> & rhs);

	template < class T_ro, class Container_ro >
	friend bool		operator<( const stack<T_ro, Container_ro> & lhs, const stack<T_ro, Container_ro> & rhs);

	template < class T_ro, class Container_ro >
	friend bool		operator<=( const stack<T_ro, Container_ro> & lhs, const stack<T_ro, Container_ro> & rhs);

	template < class T_ro, class Container_ro >
	friend bool		operator>( const stack<T_ro, Container_ro> & lhs, const stack<T_ro, Container_ro> & rhs);

	template < class T_ro, class Container_ro >
	friend bool		operator>=( const stack<T_ro, Container_ro> & lhs, const stack<T_ro, Container_ro> & rhs);

protected:
	container_type		_ct;
}; // end of class stack

template < class T, class Container >
bool		operator==( const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return (lhs._ct == rhs._ct);
}

template < class T, class Container >
bool		operator!=( const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return (lhs._ct != rhs._ct);
}

template < class T, class Container >
bool		operator<( const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return (lhs._ct < rhs._ct);
}

template < class T, class Container >
bool		operator<=( const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return (lhs._ct <= rhs._ct);
}

template < class T, class Container >
bool		operator>( const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return (lhs._ct > rhs._ct);
}

template < class T, class Container >
bool		operator>=( const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return (lhs._ct >= rhs._ct);
}

}; // end fo namespace


#endif
