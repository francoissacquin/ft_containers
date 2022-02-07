#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

// Defining the structure for integral_constant 
template <class T, T v>
struct	integral_constant
{
	static const T						value = v;
	typedef T							value_type;
	typedef integral_constant<T, v>		type;
	operator	T() { return v; };
};

// During compilation, we instantiate an integral_constant as true-type to represent the bool value "true"
typedef		integral_constant<bool, true> true_type;

// We do the same thing but for "false"
typedef		integral_constant<bool, false> false_type;

// This is so that any type that ISN'T all the following true_type polymorphism will be considered false
template <class T>	struct	is_integral: public false_type {};

template <class T>	struct	is_integral<const T>: public is_integral<T> {};

template<>	struct	is_integral<unsigned char> : public true_type {};
template<>	struct	is_integral<unsigned short> : public true_type {};
template<>	struct	is_integral<unsigned int> : public true_type {};
template<>	struct	is_integral<unsigned long> : public true_type {};
template<>	struct	is_integral<unsigned long long> : public true_type {};

template<>	struct	is_integral<signed char> : public true_type {};
template<>	struct	is_integral<short> : public true_type {};
template<>	struct	is_integral<int> : public true_type {};
template<>	struct	is_integral<long> : public true_type {};
template<>	struct	is_integral<long long> : public true_type {};

template<>	struct	is_integral<char> : public true_type {};
template<>	struct	is_integral<bool> : public true_type {};

template<>	struct	is_integral<wchar_t> : public true_type {}; // is this necessary?

} // end of namespace ft

#endif
