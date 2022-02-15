#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{

// why we need enable_if, a look at SFINAE : https://stackoverflow.com/questions/3407633/explain-c-sfinae-to-a-non-c-programmer

template <bool B, class T = void>
struct enable_if
{
	//nothing here
};

template <class T>
struct enable_if<true, T>
{
	typedef T		type;
};

} // end of namespace

#endif
