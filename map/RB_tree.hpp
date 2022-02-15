#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include "./pair.hpp"
#include <iostream>

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

	// No constructor necessary here because we are using cpp's implicit default constructor for creating nodes.

	bool	operator==( const Node & rhs )
	{
		return (value._first == rhs.value._first);
	}

	Node &	operator=( const Node & rhs )
	{
		if (this != &rhs)
		{
			data = rhs.data;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			color = rhs.color;
		}
		return *this;
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
	typedef	Node *										NodePtr;
	// the rebind<type> of std::allocator gives usaccess to its member type "other" which serves as allocator for elements of type <type>


	//CONSTRUCTOR//
	RB_tree( const allocator_type & alloc = allocator_type()): _pair_alloc(alloc), _root(NULL)
	{
		_TNULL = _node_alloc.allocate(1);
		_TNULL->right = NULL;
		_TNULL->left = NULL;
		_TNULL->color = 0;
		root = TNULL;
	}


	// // Pre-Order traversal : Node -> left sub-tree -> right sub-tree
	// void		pre_order()
	// {
	// 	pre_order_helper(this->_root);
	// }


	// // In-Order traversal : left sub-tree -> Node -> right sub-tree
	// void		in_order()
	// {
	// 	in_order_helper(this->_root)
	// }


	// // Post-Order traversal : left sub-tree -> right sub-tree -> Node
	// void		post_order()
	// {
	// 	post_order_helper(this->_root)
	// }


	// searching the tree for k key and returning the corresponding node
	NodePtr		search_tree(value_type k)
	{
		return search_tree_helper(this->_root, k);
	}


	// finding node with minimum key
	NodePtr		minimum(NodePtr n)
	{
		while (n->left != _TNULL)
			n = n->left;
		return n;
	}


	NodePtr		maximum(NodePtr n)
	{
		while (n->right != _TNULL)
			n = n->right;
		return n;
	}


	// find the successor of a given node
	NodePtr		successor(NodePtr x)
	{
		// if the right sub-tree is not null, the successor is the leftmost node in the right sub-tree
		if (x->right != _TNULL)
		{
			return minimum(x->right);
		}
		//else it is the lowest ancestor of x whose left child is also an ancestor of x
		NodePtr	 y = x->parent;
		while (y != _TNULL && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}


	//find the predecessor of a given node
	NodePtr		predecessor(NodePtr x)
	{
		// if the left tree is not null, the predecessor is the right most node in the left sub-tree
		if (x->left != _TNULL)
			return maximum(x->left);
		//else it is the highest ancestor of x whose right child is also an ancestor of x
		NodePtr y = x->parent;
		while (y != _TNULL && x == y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}


	//rotate left at Node x
	void	left_rotate(NodePtr x)
	{
		NodePtr		y = x->right;
		x->right = y->left;
		if (y->left != _TNULL)
		{
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == NULL)
		{
			this->_root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}


	//rotate right at Node x
	void	right_rotate(NodePtr x)
	{
		NodePtr		y = x->left;
		x->left = y->right;
		if (y->right != _TNULL)
		{
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == NULL)
		{
			this->root = y;
		}
		else if (x == x->parent->right)
		{
			x->parent->right = y;
		}
		else
		{
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}


	void	insert(value_type d)
	{
		NodePtr		new_node;
		
		new_node = _node_alloc.allocate(1);
		_pair_alloc.construct(new_node->data, d);
		new_node->parent = NULL;
		node->left = _TNULL;
		node->right = _TNULL;
		node->color = 1; // new node must be red

		NodePtr 	y = NULL;
		NodePtr 	x = this->_root;

		while (x != _TNULL)
		{
			y = x;
			if (new_node->data < x->data) // we go down the tree to place the new_node by comparing its data value with existing nodes.
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		// so we have x at the bottom of the tree ( as TNULL ) and y as its parent
		// so we know we can place the new_node  with y as its parent
		new_node->parent = y;
		if (y == NULL) // in case the tree is empty
		{
			this->_root = new_node;
		}
		else if (new_node->data < y->data) // we check by comparing data values wether new_node goes to the left or right of its parent
		{
			y->left = new_node;
		}
		else
		{
			y->right = new_node;
		}

		//if the new_node has become root, we simply return
		if (new_node->parent == NULL)
		{
			new_node->color = 0;
			return ;
		}

		// if the grandparent is null, we simply return ( new_node is a child of _root )
		if (new_node->parent->parent == NULL)
		{
			return ;
		}

		// AND NOW LET'S FIX THE TREE
		fix_insert(new_node);
	}


	NodePtr		get_root( void )
	{
		return this->root;
	}


	void		delete_node(value_type d)
	{
		delete_node_helper(this->root, d);
	}


	// CA C'EST POUR FAIRE JOLI, ON VERRA POUR L'ENLEVER PLUS TARD
	void		print_tree( void )
	{
		if (root != TNULL)
			print_helper(this->root, "", true);
	}



private:
	allocator_type			_pair_alloc;
	node_allocator_type		_node_alloc;
	node *					_root;
	node *					_TNULL;

	// Pour l'instant pas besoin
	// void initializeNULLNode(NodePtr node, NodePtr parent) {}

	NodePtr		search_tree_helper(NodePtr n, value_type k)
	{
		if (n == TNULL || k == n->data) // if current node is empty or k is equal to current node data we return root
		{
			return root;
		}
		if (k < n->data) // we progress throught he tree by comapring data values, in case the data is a pair, the pair operator overloads compare key first
		{
			return search_tree_helper(n->left, k);
		}
		else
		{
			return search_tree_helper(n->right, k);
		}
	}

	void		fix_delete(NodePtr x)
	{
		NodePtr		s;

		while (x != _root && x->color == 0)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right; // We make S the right neighbor of X
				if (s->color == 1) // CASE 3.1 DELETION : X's sibling S is red
				{
					s->color = 0;// We switch colors between S and X's parent
					x->parent->color = 1;
					left_rotate(x->parent); // And then perform a left rotation on X's parent
					s = x->parent->right; // the right sibling of S's new position becomes S
				} // This reduces case 3.1 to cases 3.2, 3.3 or 3.4.
				if (s->left->color == 0 && s->right->color == 0) // CASE 3.2 DELETION : X's sibling S is black and both S's children are black
				{
					s->color = 1; // We change S's color to red
					x = x->parent; // and we make X's parent the new X and this leads us to case 3.1
				}
				else
				{
					if (s->right->color == 0) // CASE 3.3 DELETION: S is black, S's left child is black and S's right child is black
					{
						s->left->color = 0;
						s->color = 1;
						right_rotate(s);
						s = x->parent->right;
					}

				}
			}
		}

	}



}





} // end of namespace

#endif
