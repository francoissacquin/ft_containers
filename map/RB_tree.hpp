#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include "./pair.hpp"

namespace ft
{

//NODE IMPLEMENTATION//
template < typename T > 
class Node
{
public:
	T		data;
	Node	*parent;
	Node	*left;
	Node	*right;
	int		color; // 1 = Red, 0 = Black;

	Node( T & p ): data(p), parent(), left(NULL), right(NULL), color(0)
	{
		// nothing here
	}

	Node( const Node & src ): data(src.data), parent(src.parent), left(src.left), right(src.right), color(src.color)
	{
		// nothing here
	}

	bool	operator==( const Node & rhs )
	{
		return (value._first == rhs.value._first);
	}
};


// RB_TREE IMPLEMENTATION//
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator < pair < const Key, T > > >
class RB_tree
{
public:

	typedef Key											key_type;
	typedef T											mapped_type;
	typedef ft::pair<const Key, T>						value_type;
	typedef Compare										key_compare;
	typedef Node<value_type>							node;
	typedef Alloc										allocator_type;
	// typedef iterator
	typedef size_t										size_type;
	typedef Alloc::template rebind<node>::other			node_allocator_type;
	// the rebind<type> of std::allocator gives usaccess to its member type "other" which serves as allocator for elements of type <type>


	//CONSTRUCTOR//
	RB_tree( const allocator_type & alloc = allocator_type()): _pair_alloc(alloc), _root(NULL)
	{
		TNULL = _node_alloc.allocate(1);
		TNULL.right = NULL;
		TNULL.left = NULL;
		TNULL.color = 0;
	}

	// Pre-Order traversal : Node -> left sub-tree -> right sub-tree
	void	preorder()
	{
		preOrderHelper(this->_root);
	}

	// In-Order traversal : left sub-tree -> Node -> right sub-tree
	void	inorder()
	{
		inOrderHelper(this->_root)
	}

	// Post-Order traversal : left sub-tree -> right sub-tree -> Node
	void	postorder()
	{
		postOrderHelper(this->_root)
	}

	// searching the tree for k key and returning the corresponding node
	node	searchTree(key_type k)
	{
		return searchTreeHelper(this->_root, k);
	}

	// finding node with minimum key
	node	minimum(node n)
	{
		while (n.left != TNULL)
			n = n.left;
		return n;
	}

	node	maximum(node n)
	{
		while (n.right != TNULL)
			n = n.right;
		return n;
	}

	// find the successor of a given node
	node	successor(node x)
	{
		// if the right sub-tree is not null, the successor is the leftmost node in the right sub-tree
		if (x.right != TNULL)
		{
			return minimum(x.right);
		}
		//else it is the lowest ancestor of x whose left child is also an ancestor of x
		node	y(x.parent);
		while (y != TNULL && x == y.right)
		{
			x = y;
			y = y.parent;
		}
		return y;
	}

	//find the predecessor of a given node
	node	predecessor(node x)
	{
		// if the left tree is not null, the predecessor is the right most node in the left sub-tree
		if (x.left != TNULL)
			return maximum(x.left);
		//else it is the highest ancestor of x whose right child is also an ancestor of x
		node y(x.parent);
		while (y != TNULL && x == y.left)
		{
			x = y;
			y = y.parent;
		}
		return y;
	}





private:
	allocator_type			_pair_alloc;
	node_allocator_type		_node_alloc;
	node *					_root;
	node *					_TNULL; // ghost?

	void



}





} // end of namespace

#endif
