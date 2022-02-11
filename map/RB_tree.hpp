#ifndef RB_TREE_HPP
# define RB_TREE_HPP

namespace ft
{

struct Node
{
	pair	data;
	Node	*parent;
	Node	*left;
	Node	*right;
	bool	color; // 1 = Red, 0 = Black;
};

typedef	Node	*NodePtr;





} // end of namespace

#endif
